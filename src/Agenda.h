#ifndef AGENDA_H
#define AGENDA_H

#include "Coordinates.h"
#include "Time.h"
#include "Day.h"
#include "Activity.h"

#include <vector>
#include <string>

class Agenda
{

private:
    std::vector<Activity> activities;

public:
    Agenda() {}
    bool addActivity();
    bool addActivity(Activity activity);
    bool isOverlap(Activity activity);
    /*
     * @brief - Verifica se existem 2 actividades no mesmo dia
     *
     * @param - nome da atividade
     * @param - day of the activity
     *
     */
    bool duplicateActivities(std::string name,Day day);

    /*
     *  @brief - Remove uma atividade com aquele nome naquele dia
     *  se existirem 2 atividades no mesmo dia com o mesmo nome pergunta a hora de começo da atividade, sendo que o
     *  hoario de cada atividade em cada dia é unico (nao existem atividades sobrepostas)
     *
     * @param - nome da atividade
     * @param - day of the activity
     *
     * @return - true if removed with success, false otherwise.
     */
    bool removeActivity(std::string name, Day day);
    bool show(Day day);
    std::vector<Activity> ActivitiesOfTheDay(Day day);
    void loadActivities();
    void saveActivities()const;
};

#endif
