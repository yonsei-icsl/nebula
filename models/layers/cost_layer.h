#ifndef __COST_LAYER_H__
#define __COST_LAYER_H__

#include "layer.h"
#include "gemm.h"

namespace nebula {
  
class cost_layer_t : public layer_t {
public :
    cost_layer_t(network_t *m_network, layer_t *m_prev_layer, layer_type_t m_layer_type);
    ~cost_layer_t();

    // Initialize layer.
    void init(section_config_t m_section_config);
    // Initialize weight from file.
    void init_weight(std::fstream &m_weight_file);
    // Initialize weight from scratch.
    void init_weight();
    // Forward propagation
    void forward();
    // Backward propagation
    void backward();
    // Layer update
    void update();
    // Store weight.
    void store_weight(std::fstream &m_weight_file);

#ifdef GPU_ENABLED
    // Forward propagation
    void _forward_();
    // Backward propagation
    void _backward_();
    // Network update
    void _update_(); 
#endif

private:
    cost_type_t cost_type;      // Cost type
};

}
// End of namespace nebula.

#endif

