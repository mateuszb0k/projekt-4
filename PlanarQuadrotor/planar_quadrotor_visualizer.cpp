#include "planar_quadrotor_visualizer.h"

PlanarQuadrotorVisualizer::PlanarQuadrotorVisualizer(PlanarQuadrotor* quadrotor_ptr) : quadrotor_ptr(quadrotor_ptr) {}

/**
 * TODO: Improve visualizetion
 * 1. Transform coordinates from quadrotor frame to image frame so the circle is in the middle of the screen
 * 2. Use more shapes to represent quadrotor (e.x. try replicate http://underactuated.mit.edu/acrobot.html#section3 or do something prettier)
 * 3. Animate proppelers
 */
bool isColorSwitched = false;
void PlanarQuadrotorVisualizer::render(std::shared_ptr<SDL_Renderer>& gRenderer) {
    Eigen::VectorXf state = quadrotor_ptr->GetState();
    float q_x, q_y, q_theta;

    /* x, y, theta coordinates */
    q_x = state[0];
    q_y = state[1];
    q_theta = state[2];
    int quadrotor_size[2] = { 100,15 };
    int connector_size[2] = { 5, 15 };
    int propeller_size[2] = { 15, 7 };
    int quadrotorcolor= 0xFF43523D;
    int connectorcolor= 0xFF000000;
    int propellercolor= 0xFF01575E;
    int propellercolor2 = 0xFF889FBD;
    float quadrotor_left[2] = { q_x - quadrotor_size[0] / 2 * cos(q_theta),q_y - quadrotor_size[0] / 2 * sin(q_theta) };
    float quadrotor_right[2] = { q_x + quadrotor_size[0] / 2 * cos(q_theta),q_y + quadrotor_size[0] / 2 * sin(q_theta) };

    float connector_distance[2] = { quadrotor_size[0] * 0.9 * cos(q_theta),quadrotor_size[0] * 0.9 * sin(q_theta) };
    float connector_length[2] = { -connector_size[1] * sin(q_theta), connector_size[1] * cos(q_theta) };

    float connector_left_base[2] = { quadrotor_right[0] - connector_distance[0],quadrotor_right[1] - connector_distance[1] };
    float connector_left_top[2] = { quadrotor_right[0] - connector_distance[0] - connector_length[0],quadrotor_right[1] - connector_distance[1] - connector_length[1] };
    float connector_right_base[2] = { quadrotor_left[0] + connector_distance[0],quadrotor_left[1] + connector_distance[1] };
    float connector_right_top[2] = { quadrotor_left[0] + connector_distance[0] - connector_length[0],quadrotor_left[1] + connector_distance[1] - connector_length[1] };
    float propeller_left1[2]={connector_left_top[0]-(propeller_size[0]),connector_left_top[1]};
    float propeller_left2[2]={connector_left_top[0]+ propeller_size[0],connector_left_top[1]};
    float propeller_right1[2]={connector_right_top[0]- propeller_size[0],connector_right_top[1]};
    float propeller_right2[2]={connector_right_base[0]+ propeller_size[0],connector_right_top[1]};
    // Draw quadrotor
    thickLineColor(gRenderer.get(), quadrotor_left[0], quadrotor_left[1], quadrotor_right[0], quadrotor_right[1], quadrotor_size[1], quadrotorcolor);
    thickLineColor(gRenderer.get(), connector_left_base[0], connector_left_base[1], connector_left_top[0], connector_left_top[1], connector_size[0], connectorcolor);
    thickLineColor(gRenderer.get(), connector_right_base[0], connector_right_base[1], connector_right_top[0], connector_right_top[1], connector_size[0], connectorcolor);
    isColorSwitched = !isColorSwitched;
    if (isColorSwitched) {
		propellercolor = propellercolor2;
        propellercolor2= 0xFF01575E; //propeller1 color 
	}
    filledEllipseColor(gRenderer.get(), propeller_left1[0], propeller_left1[1], propeller_size[0], propeller_size[1], propellercolor);
    filledEllipseColor(gRenderer.get(), propeller_right1[0], propeller_right1[1], propeller_size[0], propeller_size[1], propellercolor);
    filledEllipseColor(gRenderer.get(), propeller_left2[0], propeller_left2[1], propeller_size[0], propeller_size[1], propellercolor2);
    filledEllipseColor(gRenderer.get(), propeller_right2[0], propeller_right2[1], propeller_size[0], propeller_size[1], propellercolor2);
  //  SDL_SetRenderDrawColor(gRenderer.get(), 0xFF, 0x00, 0x00, 0xFF);
    //filledCircleColor(gRenderer.get(), q_x, q_y, 30, 0xFF0000FF);
}