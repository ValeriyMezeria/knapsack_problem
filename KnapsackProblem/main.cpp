#include <fstream>

using namespace std;

//returns capacity of knapsack
int Read(string filename, int** v, int**  w, int& size)
{
	int result, tmp;
	
	ifstream is(filename);

	if (!is.bad())
	{
		is >> result >> size;

		*v = new int [size];
		*w = new int [size];
		
		for (int i = 0; i < size; i++)
		{
			is >> tmp;
			(*v)[i] = tmp;
			is >> tmp;
			(*w)[i] = tmp;
		}
	}

	return result;
}

//solution function, optimized for maximum perfomance
//returns maximum value of staff that can put to knapsack
//don`t save specific objects, that should be put into knapsack
int OPT(int N, int W, int* v, int* w)
{
	int tmp;
	int* M = new int [W + 1];

	for (int i = 0; i < W + 1; i++)
		M[i] = 0;

	for (int i = 0; i < N; i++)
		for (int j = W; j > -1; j--)
			if (j >= w[i] && (tmp = M[j - w[i]] + v[i]) > M[j])
				M[j] = tmp;

	tmp = M[W];

	delete[] M;

	return tmp;
}

int main(int argc, char* argv[])
{
	int* v;
	int* w;
	int size;
	int result;

	int W = Read(argv[1], &v, &w, size);

	result = OPT(size, W, v, w);

	ofstream os("output.txt");

	os << result;
	os.close();

	delete[] w;
	delete[] v;

	return 0;
}