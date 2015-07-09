#include "stdafx.h"
#include "FigureFactory.h"

/*
*Cria um plano
*
*@param	x	comprimento do plano
*@param	z	largura do plano
*@return  figura com todos os pontos do plano criado
*/
Figure FigureFactory::createPlane(float x, float z){
	Figure f;
	float p[3] = {x/2, 0,z/2};
	createPlaneAux(&f,p,2,0);
	return f;
}

/*
*Fun��o auxiliar � cria��o de planos, utilizada na cria��o de cubos e paralelipipedos
*
*@param	f endere�o da figura destino
*@param p ponto inicial
*@param axisFirst	vari�vel de aux�lio na orienta��o
*@param axisSecond	vari�vel de aux�lio na orienta��o
*/
void FigureFactory::createPlaneAux(Figure* f, float p[3], int axisFirst, int axisSecond) {
	f->append({ p[0], p[1], p[2] });
	p[axisFirst] = -p[axisFirst];
	f->append({ p[0], p[1], p[2] });
	p[axisSecond] = -p[axisSecond];
	f->append({ p[0], p[1], p[2] });
	f->append({ p[0], p[1], p[2] });
	p[axisFirst] = -p[axisFirst];
	f->append({ p[0], p[1], p[2] });
	p[axisSecond] = -p[axisSecond];
	f->append({ p[0], p[1], p[2] });
}