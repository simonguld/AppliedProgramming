import numpy as np
import sys

#load data
x_data = np.loadtxt('dataX.dat')
y_data = np.loadtxt('dataY.dat')
x_test = np.loadtxt('dataXtest.dat')

#extract number of test and data points

dim = np.size( x_data[0,:])
N_data = np.size(y_data)
N_test = np.size(x_test[:, 0])

def log_func (omega, y, x):
    val = 0
    for i in range (N_data):
        val += np.log( 1 + np.exp(- y[i] * np.dot(omega, x[i,:])))
    return 1/N_data * val

def grad_func (omega,y,x):
    val = np.zeros(dim)
    for i in range(N_data):
        val -= y[i] * 1 /(1+np.exp(y[i] * np.dot(omega, x[i,:]))) * x[i,:]
    return 1/N_data * val

# Find optimal omega - it is independent of the data points
loop_max = int(1e5)
iterations = 0
omega = np.zeros(dim)
tol = 1e-7
alpha = 0.6


while True:
    grad = grad_func(omega,y_data,x_data)
    omega -= alpha * grad
    iterations += 1
    norm = np.linalg.norm(grad)
    if norm < tol or iterations == loop_max:
        print ("norm(gradient) = ", norm, " in ", iterations, " iterations")
        break

orig_output = sys.stdout
with open ('LogReg.txt', 'w') as f:
    sys.stdout = f
    for i in range (N_test):
        print(np.sign(np.dot(omega, x_test[i,:])))

    # Redirect output stream to terminal
    sys.stdout = orig_output

labels_test = np.loadtxt("LogReg.txt")

x_log_labels = np.zeros(N_test)
number_of_errors = 0

for i in range (N_test):
    x_log_labels[i] = np.sign ( np.dot(omega,x_data[i,:]) )
    if int(x_log_labels[i]) != int(y_data[i]):
        number_of_errors += 1

print ("Number of labels different from nearest neighbours = ", number_of_errors)
