import pandas as pd
df=pd.read_excel("../data/sample.xlsx")
#個人情報保護のため一時名前ではなく出席番号で管理
#のちにStreamlitに移すつもり
your_class=input()
class_dict={'2-8 SS':0, '2-8 MS':1, '2-8':2}
from random import choice
class_number=class_dict[your_class]
class_data=df.iloc[class_number]
n=class_data['人数']
attendance_number_start=class_data['最初の出席番号']
h,w=class_data['縦の長さ'],class_data['横の長さ']
g=class_data['席'].split()
grid=[]
for i in g:
  grid.append(list(i))
l = [i for i in range(1, n+1)]
name = class_data['名前(出席番号順)'].split()
max_name_length=max([len(i)for i in name])
for i in range(len(name)):
  if i+attendance_number_start<=9:p=str(i+attendance_number_start)+" "
  else:p=str(i+attendance_number_start)
  name[i]=p+"."+name[i]+"  "*(max_name_length-len(name[i]))
fix_number=class_data['固定人数']
if fix_number!=0:
  fix_data=list(map(int,class_data['固定者の番号、位置'].split()))
for i in range(fix_number):
  grid[fix_data[3*i+1]-1][fix_data[3*i+2]-1]=name[fix_data[3*i]-attendance_number_start]
  l.remove(fix_data[3*i]-attendance_number_start+1)
"""no=input().split()
for i in range(len(no)):
  l.remove(no[i])
  p=no[i]
  no[i]=name[p-1]
for i in range(10-len(no)):
  no.append("o")
kotei=[]
for i in range(len(kotei)):
  grid[0][i+1]=name[kotei[i]-1]+"  "*(8-len(name[kotei[i]-1]))
  l.remove(kotei[i])
nk=[k for k in range(1,11-len(kotei))]"""
tf=True
"""for i in range(2):
  for j in range(w):
    if i == 0 and (j == 0 or j == 5) or grid[i][j]!="o":
      continue
    c = choice(nk)
    grid[i][j]=no[c-1]+"  "*(8-len(no[c-1]))
    nk.remove(c)"""
for i in range(0,h):
  for j in range(0,w):
    if grid[i][j]=="x":
      grid[i][j]="   "+"  "*max_name_length
      continue
    if grid[i][j]=="o":
      c=choice(l)
      grid[i][j]=name[c - 1]
      l.remove(c)
      
print()
for i in range(h):
  grid[i]=" ".join(grid[i])
print("\n".join(grid))