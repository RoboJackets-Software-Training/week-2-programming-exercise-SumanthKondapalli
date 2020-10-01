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

std::vector<double> readInVector(std::string s) {
	int prev_location = 0;
	int next_location = 0;
	std::vector<double> result;
	while(s.find(',', prev_location) != std::string::npos) {
		next_location = s.find(',', prev_location);
		result.push_back(std::stod(s.substr(prev_location, next_location - prev_location)));
		next_location++;
		prev_location = next_location;
	}
	result.push_back(std::stod(s.substr(prev_location, std::string::npos)));
	return result;
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