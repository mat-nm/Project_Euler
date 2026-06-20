import datetime

def pb19(fyear=1901, lyear=2000):
	res = 0
	for year in range(fyear, lyear + 1):
		for month in range(1, 13):
			if datetime.date(year, month, 1).weekday() == 6:
				res += 1
	print(res)
	return res

pb19()