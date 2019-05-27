#ifndef AGENDA_H
#define AGENDA_H

#include <vector>
#include <string>


#include "Time.h"
#include "Day.h"
#include "Activity.h"


class Agenda {

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
     *  se existirem 2 atividades no mesmo dia com o mesmo nome pergunta a hora de come�o da atividade, sendo que o
     *  hoario de cada atividade em cada dia � unico (nao existem atividades sobrepostas)
     *
     * @param - nome da atividade
     * @param - day of the activity
     *
     * @return - true if removed with success, false otherwise.
     */
    bool removeActivity(std::string name, Day day);
    bool show(Day day);
    std::vector<Activity> activitiesOfTheDay(Day day) const;
    void loadActivities();
    void saveActivities() const;
    std::vector<Coordinates> getCoords(Day day) const;
    bool onTime(Activity a, Activity b, Time travel) const;
    /**
     * @brief - See if we going to be on time
     * 
     * @param - vetor com todos os tempos de viagem
     * @param - day be analized
     */
    std::vector<bool> onTime(std::vector<Time> travelTime, Day day) const;
    void show(std::vector<bool> onTime, Day day ) const;
};

#endif
