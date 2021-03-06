#include "asum.h"
#include "godunov.h"
#include "equationsystemreader.h"
#include "solutionwriter.h"


int main() {

	std::string name_file = "input\\input.txt";
	IEquationSystemReader *equationSystemReader = new EquationSystemReader();
	EquationSystem eq = equationSystemReader->readFile(name_file);

	int menuItem;
	while (true) {
		std::cout << "Menu: \n";
		std::cout << "0 - Godunov \n";
		std::cout << "1 - ASUM \n";
		std::cout << "2 - input  file name \n";
		std::cout << "3 - Exit \n";
		std::cout << "Enter:";
		std::cin >> menuItem;
		if (!std::cin) {
			break;
		}
		
		Solver *ptr;
		
		if (menuItem == 0) {
			—omputationalGrid grid;
			double maxT;
			std::cout << "Enter the number of partitions for x:";
			std::cin >> grid.numberOfXSplits;
			std::cout << "Enter max T:";
			std::cin >> maxT;

			Godunov a;
			Variables<Array<double>*> result;
			ptr = &a;
			ptr->init(eq);
			if ((ptr->init—omputationalGrid(grid, maxT)).success) {
				result = ptr->solve();
				(new SolutionWriter())->write("Godunov", result);
				delete result.p; delete result.ro, delete result.u;
			}
		}
		else if (menuItem == 1) {
			—omputationalGrid grid;
			double maxT;

			std::cout << "Enter the number of partitions for x:";
			std::cin >> grid.numberOfXSplits;
			std::cout << "Enter the number of partitions for t:";
			std::cin >> grid.numberOfTimeSplits;
			std::cout << "Enter max T:";
			std::cin >> maxT;

			ASUM a;
			Variables<Array<double>*> result;
			ptr = &a;
			ptr->init(eq);
			const Response resp = ptr->init—omputationalGrid(grid, maxT);
			if (resp.success) {
				result = ptr->solve();
				(new SolutionWriter())->write("AUSM", result);
				delete result.p; delete result.ro, delete result.u;
			}
			else {
				std::cout << resp.message;
			}
		}
		else if (menuItem == 2) {
			Variables<Array<double>*> result;

			std::cin >> name_file;
			std::cout << "\n file name: " << name_file << "\n";
			eq = equationSystemReader->readFile(name_file);
			
		}
		else if (menuItem == 3) {
			break;
		}
		else {
			std::cout << "The entered item is not in the menu!";
		}
		std::cout << "\n\n";
	}
	delete equationSystemReader;
	system("pause");
	return 0;
}