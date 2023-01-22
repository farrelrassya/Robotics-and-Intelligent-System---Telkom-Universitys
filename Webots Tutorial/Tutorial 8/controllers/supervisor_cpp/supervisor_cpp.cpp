#include <webots/Supervisor.hpp>

#define TIME_STEP 32

using namespace webots;

int main() {
  Supervisor *supervisor = new Supervisor();
  // pointer to nodes jerry
  Node *Slave_node = supervisor->getFromDef("Jerry");
  
  // pointer to node Tom
  Node *Master_node = supervisor->getFromDef("Tom");
  // Pointer to translation of tom and jerry
  
  Field *Slave_trans_field = Slave_node->getField("translation");
  Field *Master_trans_field = Master_node->getField("translation");
  
  // Set an array of 3 numbers
  double pos[3] = {0, 0, 0};

  while (supervisor->step(TIME_STEP) != -1) {
    // Take Co-ordinates of Tom
    const double *Master_trans = Master_trans_field->getSFVec3f();

    pos[0]=Master_trans[0]+0.5;
    pos[1]=Master_trans[1]-0.1;
    pos[2]=Master_trans[2]+0.1;
    
    // Setting array to vector
    Slave_trans_field->setSFVec3f(pos);
  }
  // delete the object
  delete supervisor;
  return 0;
}