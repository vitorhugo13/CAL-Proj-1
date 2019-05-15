#include "Agenda.h"

class Agenda {
    Agenda(){ }
    std::vector<Activity *> activities;
    bool addActivity(Activity * activity){
        activities.push_back(activity);
        return true;
    }
    bool isOverlap(Activity * activity){
       for(int i=0; i < activities.size(); i++){
           //verificar sobreposições
       }
    }
};
