#include "Juego.h"
#include "Preguntando.h"

int main() {
	/*QueerQuestDeluxe::Application::EnableVisualStyles();
	QueerQuestDeluxe::Application::Run(gcnew QueerQuestDeluxe::Juego());*/
	QueerQuestDeluxe::Application::EnableVisualStyles();
	QueerQuestDeluxe::Application::Run(gcnew QueerQuestDeluxe::Preguntando());
}