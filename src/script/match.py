# simple match framework to check the difference between two programs
import subprocess, random

program_a = r'D:\Projects\code\build\bin\Debug\main.exe'
program_b = r'D:\Projects\code\build\bin\Debug\check.exe'

def gen_data():
  d = ''
  t = 5
  d += f'{t}'
  for i in range(t):
    n = random.randint(1, 20)
    d += f'\n{n}\n'
    for j in range(n):
      l = random.randint(1, 50)
      w = random.randint(1, 50)
      d += f'{l} {w} '
  return d

def run():
  d = gen_data()
  data_file = open('data.txt', 'w')
  data_file.write(d)
  data_file.close()
  data_file = open('data.txt', 'r')
  a_out_file = open('out_a.txt', 'w')
  p_a = subprocess.Popen([program_a], stdin=data_file, stdout=a_out_file)
  a_out_file.close()
  data_file.close()
  data_file = open('data.txt', 'r')
  b_out_file = open('out_b.txt', 'w')
  p_b = subprocess.Popen([program_b], stdin=data_file, stdout=b_out_file)
  b_out_file.close()
  data_file.close()

if __name__ == '__main__':
  run()
