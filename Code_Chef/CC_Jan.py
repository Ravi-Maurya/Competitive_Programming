days = [31,28,31,30,31,30,31,31,30,31,30,31]

def get_day_year(y):
	y-=1
	return (y+(y//4 - y//100 + y//400))%7

def is_leap(year):
	if year%400==0:
		return True
	elif year%4==0 and year%100!=0:
		return True
	return False

def get_day_month(m,y):
	day = get_day_year(y)
	# print("Year 2020",end=" ")
	leap = is_leap(y)
	# print(day,leap)
	s = 0
	if m>1:
		s = 0
		for i in range(m-2+1):
			if leap and i==1:
				s+=1
			s+=days[i]
		s %= 7
	day += s
	day %= 7
	return day

def long_challenge(tmp):
	i = 1
	st = en = -1
	while tmp!=4:
		i+=1
		tmp+=1
		tmp%=7
	st = i
	en = st+10
	return st,en

def cookoff(m,y,cnt_days,last):
	c = 0
	while True:
		if last==6:
			c+=1
		if c==2:
			break
		last-=1
		cnt_days-=1
		if last<0:
			last = 6
	return cnt_days
def rec(m1,y1,lcst,lcen,coock,res):
	if lcst<=coock and coock<lcen:
			res = res+1
	m1+=1
	if m1>12:
		m1 = 1
		y1+=1
	return m1,y1,res

def solve(m1,y1 , m2,y2):
	res = 0
	day = get_day_month(m1,y1)
	lcst,lcen = long_challenge(day)
	cnt_days = days[m1-1]
	if m1==2 and is_leap(y1):
		cnt_days+=1
	last = (day + cnt_days%7)%7
	if last==0:
		last = 6
	else:
		last-=1
	coock = cookoff(m1,y1,cnt_days,last)
	m1,y1,res = rec(m1, y1, lcst, lcen, coock, res)
	while (m1<=m2 and y1<=y2) or (m1>m2 and y1<y2):
		# print(m1,y1)
		day = (last+1)%7
		lcst,lcen = long_challenge(day)
		cnt_days = days[m1-1]
		if m1==2 and is_leap(y1):
			cnt_days+=1
		last = (day + cnt_days%7)%7
		if last==0:
			last = 6
		else:
			last-=1
		coock = cookoff(m1,y1,cnt_days,last)
		m1,y1,res = rec(m1, y1, lcst, lcen, coock, res)
	return res


def main():
	T = int(input())
	for _ in range(T):
		m1, y1 = map(int,input().split())
		m2, y2 = map(int,input().split())
		print(solve(m1, y1, m2, y2))
	return

main()