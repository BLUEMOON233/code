T = int(input())

for _ in range(T):
	s = input().split(' ')
	a = int(s[0])
	b = int(s[2])
	op = s[1]
	if op == '+':
		print(a + b)
	elif op == '-':
		print(a - b)
	elif op == '*':
		print(a * b)
	elif op == '/':
		print(a // b)
	elif op == '%':
		print(a % b)
	elif op == '^':
		print(a ** b)