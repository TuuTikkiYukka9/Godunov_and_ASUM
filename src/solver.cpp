#include "solver.h"

void Solver::init(const EquationSystem &eq) {
	bcLeft = eq.leftBoundaryCondition;
	bcRight = eq.rightBoundaryCondition;
	x0 = eq.x0;
	maxX = eq.maxX;
	minX = eq.minX;
};

