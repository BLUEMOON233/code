import random
import csv

def generate_random_data(used_numbers):
    number = random.randint(2021900000, 2021909999)
    while number in used_numbers:
        number = random.randint(2021900000, 2021909999)
    used_numbers.add(number)
    name = ''.join(random.choices('abcdefghijklmnopqrstuvwxyz', k=5))
    gender = random.choice(['男', '女'])
    score = round(random.uniform(60, 100), 2)
    is_fill = random.choices([1, 0], [97, 3])[0]
    
    if is_fill == 1:
        majors = random.sample(range(1, 5), 3)
        major_1, major_2, major_3 = majors
    else:
        major_1 = major_2 = major_3 = -1
    
    return [number, name, gender, score, is_fill, major_1, major_2, major_3]

def generate_csv_file(filename, accoutnfilename, num_rows):
    used_numbers = set()

    number_list = []

    with open(filename, 'w', newline='', encoding='utf-8') as csvfile:
        writer = csv.writer(csvfile)
        header = ['number', 'name', 'gender', 'score', 'is_fill', 'major_1', 'major_2', 'major_3']
        writer.writerow(header)
        for _ in range(num_rows):
            row_data = generate_random_data(used_numbers)
            number_list.append(row_data[0])
            writer.writerow(row_data)

    with open(accoutnfilename, 'w', newline='', encoding='utf-8') as csvfile:
        writer = csv.writer(csvfile)
        header = ['number', 'password']
        writer.writerow(header)
        for index in range(num_rows):
            writer.writerow([number_list[index], '123456']);



generate_csv_file('data.csv', 'account.csv', 300)