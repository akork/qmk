# %%
import mappings
dir(mappings)
# %%
from io import StringIO
import tokenize
import json
import mappings
import yaml
import re

keymap = {}

def args(src):
    # print("parsing args...")
    out = []
    res, next_token = fun(src)
    # print("return from fun: {0} {1}".format(res, next_token[1]))
    out.append(res)
    if next_token[1] == ",":
        # print("parsing after ,")
        res, next_token = args(src)
        for e in res:
            out.append(e)
    # print("return from args: {0} {1}".format(res, next_token[1]))
    return out, next_token

def fun(src):
    # print("parsing fun...")
    token = next(src)
    # print(token[0], token[1])
    out = []
    if token[0] == tokenize.NAME:
        out.append(token[1])
        next_token = next(src)
        if next_token[1] == "(":
            try:
                res, next_token = args(src)
            except tokenize.TokenError:
                raise SyntaxError("eof")
            for e in res:
                out.append(e)
            if next_token[1] != ")":
                raise SyntaxError("no closing bracket: {}".format(next_token[1]))
            next_token = next(src)
            return out, next_token
        return out[0], next_token
    return out, token

def parse_item(source):
    src = StringIO(source).readline
    src = tokenize.generate_tokens(src)
    res, _ = fun(src)
    return res

def convert(item):
    global keymap
    if item not in keymap:
        return None
    else:
        return keymap[item]

def apply_mods(tree, res):
    if type(tree) == list:
        item = convert(tree[0])
        if item:
            res['modifiers'] = res['modifiers'] + item
            return apply_mods(tree[1], res)
        else:
            return None
    else:
        item = convert(tree)
        if item:
            res['key_code'] = item
            return res
        else:
            return None

def item_to_json(tree):
    res = {}
    res['key_code'] = ''
    res['modifiers'] = []
    return apply_mods(tree, res)

def to_json(src):
    src = [e.strip() for e in src.split(",")]
    res = [item_to_json(parse_item(e)) for e in src]
    return res

def parse_source_file(filename):
    out = {}
    with open(filename, 'r') as f:
        # regex = re.compile('karabiner')
        rgx = []
        # rgx.append(re.compile('karabiner'))
        rgx.append(re.compile(r'//%%\s+(karabiner)'))
        rgx.append(re.compile(r'//%%\s+(plain):(\w+)'))
        rgx.append(re.compile(r'//%%\s+(mod):(\w+)'))
        rgx.append(re.compile(r'//%%\s+(oneshot):(\w+)'))
        rgx.append(re.compile(r'//%%\s+(sticky):(\w+)'))
        for line in f:
            for r in rgx:
                # match = r.search(line)
                if match := r.search(line):
                    if len(match.groups()) == 1:
                        typ = 'karabiner'
                        name = 'karabiner'
                    else:
                        typ = match.group(1)
                        name = match.group(2)
                    # print(typ, name)
                    res = ' '.join([next(f).strip() for _ in range(5)])
                    res = re.sub(re.compile(r'//|/\*|\*/'), '', res)
                    res = re.search(r'\((.*)\)', res).group(1)
                    res = [e.strip() for e in res.split(',')]
                    # print(len(res), res)
                    out[name] = {'keymap': res, 'type': typ}
    return out

def parse_keymap():
    global keymap
    with open("map.yaml", 'r') as stream1,\
         open('qmk_defines.yaml', 'r') as stream2:
        try:
            keymap = yaml.safe_load(stream1)
            qmk_keymap = yaml.safe_load(stream2)
        except yaml.YAMLError as exc:
            print(exc)
        # print(qmk_keymap)
        for e in qmk_keymap:
            if qmk_keymap[e] in keymap:
                keymap[e] = keymap[qmk_keymap[e]]
        keymap_full = {}
        for e in keymap:
            keymap_full[e] = keymap[e]
            if e.startswith('KC'):
                keymap_full[e[2:]] = keymap[e]
        keymap = keymap_full
        # print(f'{keymap=}')
    return keymap

if __name__ == '__main__':
    # res = {}
    # res['keycode'] = '' # put keycode key on first position
    parse_keymap()
    # print(keymap)
    out = parse_source_file('ak-first-keymap.c')
    print(len(out), out.keys())
    id = 'karabiner'
    print(out[id])
    parsed = item_to_json(out[id]['keymap'][0])
    print(parsed)
    id = 'en'
    print(out[id])
    parsed = item_to_json(out[id]['keymap'][1])
    print(parsed)
    # res = to_json(src)
    # parse_keymap()
    # print(keymap)
    # print(tree)
    # print(res)
    # print(len(res))
    # parse_file('ak-first-keymap.c')





# %%
import json

with open('/Users/ak/.config/karabiner/karabiner.json', 'r') as file:
    out : dict = json.load(file)

    # print(out['profiles'][0]['complex_modifications']['rules'])



