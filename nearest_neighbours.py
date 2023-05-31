import numpy as np
import sys

np.set_printoptions(precision=6)

#Load data
data_y = np.loadtxt('dataY.dat')
data_x = np.loadtxt('dataX.dat')
test_x = np.loadtxt('dataXtest.dat')

#Extract number of data and test points
N_data = np.size(data_y)
N_test = np.size(test_x[:,0])

#Define the nearest neighbor parameter
nearest_neighbours = 5

"""
original = sys.stdout
with open ('labels.dat') as f:
    sys.stdout = f
    print ('hej med dig jeg hedder kaj')
sys.stdout = original
"""


#Redirect output stream to 'labels.txt'
orig_output = sys.stdout
with open('labels.txt', 'w') as f:
    sys.stdout = f

    # Find the label of each test point
    for i in range(N_test):
        # Collect labels and distances of the nearest neighbours to a given test point
        dist_label_matrix = np.empty((nearest_neighbours, 2))
        for j in range(N_data):
            if j < nearest_neighbours:
                dist_label_matrix[j, 0] = np.linalg.norm(data_x[j, :] - test_x[i, :])
                dist_label_matrix[j, 1] = data_y[j]
            else:
                distance = np.linalg.norm(data_x[j, :] - test_x[i, :])
                max_distance = np.amax(dist_label_matrix[:, 0])
                if distance < max_distance:
                    max_index = np.argmax(dist_label_matrix[:, 0])
                    dist_label_matrix[max_index, 0] = distance
                    dist_label_matrix[max_index, 1] = data_y[j]
        # Extract and print out label
        sum = np.sum(dist_label_matrix[:, 1])
        label = sum / np.abs(sum)
        print(label)

    #Redirect output stream to terminal
    sys.stdout = orig_output

#Test whether labels match those assigned in "NN.dat".
reference_labels = np.loadtxt('NN.dat')
calc_labels = np.loadtxt('labels.txt')

number_of_errors = 0
for i in range(N_test):
    if reference_labels[i] != calc_labels[i]:
        sum += 1

print ("Number of wrongly assigned labels = ", number_of_errors)
