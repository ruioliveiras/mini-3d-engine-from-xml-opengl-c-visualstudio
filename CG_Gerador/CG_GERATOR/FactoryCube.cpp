#include "stdafx.h"
#include "FigureFactory.h"


/*
*Cria uma figura com a forma c�bica
*
*@param	lado comprimento do lado do cubo
*@return  figura com forma c�bica criada
*/
Figure FigureFactory::createCube(float lado){
	float meio = lado / 2;
	return createParallelepiped(meio, meio, meio);
}
