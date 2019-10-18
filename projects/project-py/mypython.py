import os
import random

def create_files():

	# Create Three Files, named differently.

	filename_list = []

	for x in range (0,3):

		current_filename = str(random.randint(111111,999999)) + ".tmp"
		filename_list.append(current_filename)

		os.system("touch " + current_filename)

	return filename_list


def fill_files(filenames):

	# Fill each of the files in filenames with 10 random lowercase alphabetic characters and a newline
	# Output fill text to screen

	file_data = []

	for file in filenames:

		file_contents = ''.join([random.choice("abcdefghijklmnopqrstuvwxyz") for u in range (0,10)])
		file_data.append(file_contents)
		os.system("echo \"" + file_contents + "\" >> " file)

		print(file_contents)

	



def print_integers():

	# Print two randints on 1..42 incl



	# Print product of two integers above.

if __name__ == __main__:

	file_list = create_files()
	fill_files(file_list)
	print_integers()