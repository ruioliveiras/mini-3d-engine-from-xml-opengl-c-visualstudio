#include "stdafx.h"
#include "FigureFactory.h"

/*
*Cria uma figura com a forma circular
*
*@param	raio	raio do c�rculo
*@param	fatias	n�mero de fatias
*@return  figura com forma circular criada
*/
Figure FigureFactory::createCircle(float raio, int fatias){
	Figure f;
	Point3D* p = new Point3D[2];
	p[0].x = 0; p[0].y = 0;
	p[1].x = raio; p[1].y = 0;
	createRotate(&f, p, 2, fatias);
	//createCircleAux(&f, raio, fatias, 0, 1);
	return f;
}

/*
*Fun��o auxiliar da cria��o de c�rculos, utilizada para aux�lio na constru��o de c�rculos e cones
*
*@param	f		endere�o da figura destino
*@param	raio	raio do c�rculo
*@param	fatias	n�mero de fatias
*@param altura	altura onde o c�rculo ser� desenhado
*@param orient	orienta��o do c�rculo
*/
void FigureFactory::createCircleAux(Figure* f,float raio, int fatias, float altura, int orient){
	int i;
	float angulo_cir = 2 * ((float) M_PI) / fatias;

	if (orient){
		for (i = 0; i < fatias; i++) {
			f->append({ 0, altura, 0 });
			f->append({ raio * sin(angulo_cir*i), altura, raio * cos(angulo_cir*i) });
			f->append({ raio * sin(angulo_cir*(i + 1)), altura, raio * cos(angulo_cir*(i + 1)) });
		}
	} else {
		for (i = 0; i < fatias; i++) {
			f->append({ 0, altura, 0 });
			f->append({ raio * sin(angulo_cir*(i + 1)), altura, raio * cos(angulo_cir*(i + 1)) });
			f->append({ raio * sin(angulo_cir*i), altura, raio * cos(angulo_cir*i) });
		}
	}
}


