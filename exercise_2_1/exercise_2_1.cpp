#include <vector>
#include "convolution.h"


int main() {

	std::vector<double> x = {1,2,3,4,5,6,7};
	std::vector<double> w = {2,5,6};
	bool pad = true;

	applyConvolution(x, w, pad);

}
