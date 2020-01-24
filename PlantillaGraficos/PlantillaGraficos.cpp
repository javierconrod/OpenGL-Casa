// PlantillaGraficos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <iostream>

using namespace std;

void dibujarFondo() {
	//Cesped
	glBegin(GL_QUADS);

	glColor3f(0.1f, 1.0f, 0.0f);

	glVertex3f(-1.0f, -0.5f, 0.0f);
	glVertex3f(1.0f, -0.5f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(1.0f, 1.0f, 1.0f);

	for (int i = 1; i < 360; i += 5.0)
	{
		glVertex3f ((0.5 * cos(i * 3.1416 / 180.0)) - 0.6, (0.1 * sin(i * 3.1416 / 180.0)) + 0.4, 0.0f);
	}

	glEnd();
}
void dibujarCasa() {
	//Muro
	glBegin(GL_QUADS);

	glColor3f(0.7f, 0.4f, 0.2f);

	glVertex3f(-0.3f, 0.2f, 0.0f);
	glVertex3f(0.7f, 0.2f, 0.0f);
	glVertex3f(0.7f, -0.7f, 0.0f);
	glVertex3f(-0.3f, -0.7f, 0.0f);

	glEnd();
	//Techo
	glBegin(GL_TRIANGLES);

	glColor3f(0.8f, 0.2f, 0.0f);

	glVertex3f(-0.4f, 0.2f, 0.0f);
	glVertex3f(0.2f, 0.7f, 0.0f);
	glVertex3f(0.8f, 0.2f, 0.0f);

	glEnd();
	//Ventana
	glBegin(GL_QUADS);

	glColor3f(0.8f, 0.2f, 0.0f);

	glVertex3f(0.31f, 0.1f, 0.0f);
	glVertex3f(0.6f, 0.1f, 0.0f);
	glVertex3f(0.6f, -0.2f, 0.0f);
	glVertex3f(0.31f, -0.2f, 0.0f);

	glColor3f(0.3f, 0.8f, 0.9f);

	//esquina superior izquierda
	glVertex3f(0.33f, 0.08f, 0.0f);
	glVertex3f(0.44f, 0.08f, 0.0f);
	glVertex3f(0.44f, -0.05f, 0.0f);
	glVertex3f(0.33f, -0.05f, 0.0f);

	//esquina superior derecha
	glVertex3f(0.46f, 0.08f, 0.0f);
	glVertex3f(0.58f, 0.08f, 0.0f);
	glVertex3f(0.58f, -0.05f, 0.0f);
	glVertex3f(0.46f, -0.05f, 0.0f);

	//esquina inferior izquierda
	glVertex3f(0.33f, -0.07f, 0.0f);
	glVertex3f(0.44f, -0.07f, 0.0f);
	glVertex3f(0.44f, -0.18f, 0.0f);
	glVertex3f(0.33f, -0.18f, 0.0f);

	//esquina inferior derecha
	glVertex3f(0.46f, -0.07f, 0.0f);
	glVertex3f(0.58f, -0.07f, 0.0f);
	glVertex3f(0.58f, -0.18f, 0.0f);
	glVertex3f(0.46f, -0.18f, 0.0f);

	glEnd();
	//Puerta
	glBegin(GL_QUADS);

	glColor3f(0.8f, 0.8f, 0.5f);

	glVertex3f(0.05f, -0.25f, 0.0f);
	glVertex3f(0.35f, -0.25f, 0.0f);
	glVertex3f(0.35f, -0.7f, 0.0f);
	glVertex3f(0.05f, -0.7f, 0.0f);

	glEnd();
}

void dibujarArbol() {
	glBegin(GL_QUADS);

	glColor3f(0.7f, 0.5f, 0.2f);

	glVertex3f(-0.75f, -0.2f, 0.0f);
	glVertex3f(-0.55f, -0.2f, 0.0f);
	glVertex3f(-0.55f, -0.75f, 0.0f);
	glVertex3f(-0.75f, -0.75f, 0.0f);


	glEnd();
}

void dibujarPasto() {
	glBegin(GL_LINE);

	glColor3f(0.0f, 0.0f, 0.0f);

	glVertex3f(-0.2f, -0.8f, 0.0f);
	glVertex3f(-0.3f, -0.7f, 0.0f);

	glEnd();
}

void dibujar() {
	dibujarFondo();
	dibujarCasa();
	dibujarArbol();
	dibujarPasto();
}

int main()
{
	//Declarar una ventana
	GLFWwindow* window;

	//Si no se pudo iniciar GLFW
	//Terminamos la ejecución
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	//Si se pudo iniciar GLFW
	//Inicializamos la ventana
	window = glfwCreateWindow(600, 600, "Ventana", NULL, NULL);

	//Si no se pudo crear la ventana
	//Terminamos la ejecución
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	//Establecemos la ventana como contexto

	glfwMakeContextCurrent(window);

	//una vez establecido el contexto
	//se activan las funciones "modernas" (gpu)
	glewExperimental = true;

	GLenum errores = glewInit();
	if (errores != GLEW_OK) {
		glewGetErrorString(errores);
	}

	const GLubyte* versionGL = glGetString(GL_VERSION);
	cout << "Version OpenGL: " << versionGL;




	//Ciclo de dibujo (DrawLoop)
	while (!glfwWindowShouldClose(window)) {

		//Establecer región de dibujo
		glViewport(00, 0, 600, 600);
		//Establecemos el color de borrado
		//Valores RGBA
		glClearColor(0.2, 0.7, 1, 1);
		//Borrar
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Actualizar valores y dibujar
		dibujar();
		glfwPollEvents();
		glfwSwapBuffers(window);

	}
	//Después del ciclo de dibujo
	//Eliminamos ventana y procesos de GLFW
	glfwDestroyWindow(window);
	glfwTerminate();

}