#include "Bird.hpp"
#include "Pato.hpp"
#include "Penguim.hpp"
#include "Pombo.hpp"


/*
Note que os exemplos a seguir são extremamente básicos.
No exercício anterior, a herança de priority_queue funciona muito melhor 
*/
int main(void){
	// Bird quebraCompilacao;
	Pato donald;
	donald.sing();
	donald.eat();
	donald.fly();

	Penguim happyFeet;
	happyFeet.sing();
	happyFeet.eat();
	happyFeet.fly();

	Pombo boladao;
	boladao.sing();
	boladao.eat();
	boladao.fly();
}