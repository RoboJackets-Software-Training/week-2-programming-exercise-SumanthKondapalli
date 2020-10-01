#include <vector>
#include <iostream>

std::vector<double> applyConvolution(std::vector<double> x, std::vector<double> w, bool pack_with_zeros) {

	std::vector<double> y;

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

	return y;

}

int main() {

	std::vector<double> conv =  applyConvolution({1,2,3,4,5,6,7}, {2,5,6}, false);

	std::cout << "{";

	for (int i = 0; i < conv.size() - 1; i++)
	{
		std::cout << conv[i] << ", ";
	}

	std::cout << conv[conv.size()-1] << "}" << std::endl;

}
