#include <iostream>
#include <vector>

void printVector(std::vector<double> vec) {

	std::cout << "{";

	for (int i = 0; i < vec.size() - 1; i++)
	{
		std::cout << vec[i] << ", ";
	}

	std::cout << vec[vec.size()-1] << "}" << std::endl;

}

std::vector<double> applyConvolution(std::vector<double> x, std::vector<double> w, bool pack_with_zeros) {

	std::vector<double> y;

	std::cout << "x: ";
	printVector(x);

	std::cout << "w: ";
	printVector(w);

	for (int i = 0; i < x.size(); i++) 
	{

		int conSum = 0;

		for (int j = 0; j < w.size(); j++) {

			int index = i + j - (w.size()/2);

			if (!pack_with_zeros && index < 0)
			{
				conSum += x[0] * w[j];
			}
			else if (!pack_with_zeros && index >= x.size())
			{
				conSum += x[x.size()-1] * w[j];
			}
			else {
				conSum += x[index] * w[j];
			}

		}

		y.push_back(conSum);

	}

	printVector(y);

	return y;

}