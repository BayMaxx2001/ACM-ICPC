
word = "hello World"
even_numbers = [i**2 for i in range(0,10) ]

transactions = [100,200,300,150,80]
TAX_RATE = 0.08
SERVICE_CHARGE = 0.07 
my_strings = "welcom"


def get_price_tax(bill):
	return bill + bill * TAX_RATE + bill *SERVICE_CHARGE

if __name__ == "__main__":
	# print(get_price_tax(100))
	# final_prices = [ get_price_tax(bill) for bill in transactions ]
	# print(final_prices)

	#list()-> conver String list 
	# list_of_chars = list(my_strings)
	# print(list_of_chars)

	#zip()
	wizads= ['harry', 'ron', 'her']
	pets= ['Hedwig','scaber', 'crool']

	# for wizads, pets in zip(wizads,pets):
	# 	print(f'{wizads} has {pets}') 

	# for index ,(wizads , pets) in enumerate(zip(wizads,pets)):
	# 	print(f'{index}:  {wizads} has {pets}')

	#sort()
	sorted_by_first = sorted(['hi', 'hello' , 'you', 'Code'], key = lambda el : el[1])
	print(sorted_by_first)	

	matrix = [[1,2,3],
			  [3,4,5],
			  [10,2,2]]

	for row in range(len(matrix)):
		for col in range(len(matrix)):
			print(matrix[row][col])

	#transform matrix in list
	list_converted = [matrix[row][col] for row in range(len(matrix)) for col in range(len(matrix))] 
	print(list_converted)

	#Dictionary
	my_dict = {"name": "hien", "content" : "Pro", "city" : "SING"}
	print(my_dict)
	my_dict2 = dict(name = "code" , content = "Progam" , city = "SG")
	print(my_dict2)
	
	#acces 
	content_in_dict = my_dict["content"]
	print(content_in_dict)	

	if "age" in my_dict:
		print(my_dict["name"])
	else:
		print("no")

	try:
		print(my_dict["age"])
	except KeyError: 
		print("no key")

	#add key 
	my_dict["email"] = "@gmail.com"
	print(my_dict)

	#delete 
	del my_dict["city"]
	print(my_dict)

	#delete imtems 
	my_dict["age"] = 25
	print(my_dict) 
	my_dict.popitem()
	print(my_dict)

	#loop key
	for key in my_dict.items():
		print(key, my_dict[key])


