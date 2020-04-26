# To add a new cell, type '# %%'
# To add a new markdown cell, type '# %% [markdown]'
# %%
import textwrap
import json
import re
import myparser

template_description = '''
{{
    "description": "{descr}",
    "manipulators": [
{manip}
    ]
}},'''

rule = {'description': None, 'manipulators': []}

template_oneshot = '''
{{
    "conditions": [
{cond}
    ],
    "from":
{fr},
    "to": [
{to_var},
{to_kc}
    ],
    "type": "basic"
}},'''

template_plain = '''
{{
    "from":
{fr},
    "to": [
{to_kc}
    ],
    "type": "basic"
}},'''

rules = []
template_plain = {'from': None, 'to': [], 'type': 'basic'}
res = ''
myparser.parse_keymap()
layers = myparser.parse_source_file('ak-first-keymap.c')
fr = layers['karabiner']['keymap']
id = 'en'
to, typ = layers[id]['keymap'], layers[id]['type']
rule = {'description': id, 'manipulators': []}
for i, (fr, to) in enumerate(zip(fr, to)):
    fr_kc = {'key_code': fr, 'modifiers': {'optional': ['any']}}
    # fr_kc = textwrap.dedent('''\
        # {{
            # "key_code": "{fr}",
            # "modifiers": {{
                # "optional": [
                    # "any"
                # ]
            # }}
        # }}''').format(fr=fr)
    to_kc = myparser.item_to_json(to)
    # print('to', to)
    # to_kc = to
    if fr ==  '':
        print(i, '!!', to)
        continue
    if not to_kc:
        print(i, '::', to)
        continue
    # to_kc = json.dumps(to_kc)
    if typ == 'plain':
        # entry = template_plain.copy()
        # entry['from'] = fr_kc
        # entry['to'].append(to_kc)
        entry = {'from': fr_kc, 'to': [to_kc], 'type': 'basic'}
        rule['manipulators'].append(entry)
        
        # res += template_plain.format(fr=fr_kc, to_kc=('        ' + to_kc))
    elif typ == 'oneshot':
        oneshot = id
        cond1 = textwrap.dedent('''\
            {{
                "name": "{oneshot}",
                "type": "variable_if",
                "value": 1
            }}''').format(oneshot=oneshot)
        cond2 = textwrap.dedent('''\
            {{
                "name": "{oneshot} trace",
                "type": "variable_if",
                "value": 1
            }}''').format(oneshot=oneshot)
        to_var = textwrap.dedent('''\
            {{
                "set_variable": {{
                    "name": "{oneshot} trace",
                    "value": 0
                }}
            }}''').format(oneshot=oneshot)

        res += template_oneshot.format(
            cond=cond1, fr=fr_kc, to_kc=to_kc, to_var=to_var)  + \
            template_oneshot.format(
            cond=cond2, fr=fr_kc, to_kc=to_kc, to_var=to_var)

# res = template_description.format(descr=id, manip=res[:-1])
# print(json.dumps(rule, indent=2))

with open('/Users/ak/.config/karabiner/karabiner.json', 'r') as file:
    out : dict = json.load(file)
    out['profiles'][0]['complex_modifications']['rules'] = [rule]

with open('/Users/ak/.config/karabiner/karabiner.json', 'w') as file:
    json.dump(out, file, indent=2)
    # out['profiles'][0]['complex_modifications']['rules'] = 


# %%


