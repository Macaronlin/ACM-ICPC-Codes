import re
s = input()
s = re.sub(r'[(]', '**(', s)
print(eval(s))