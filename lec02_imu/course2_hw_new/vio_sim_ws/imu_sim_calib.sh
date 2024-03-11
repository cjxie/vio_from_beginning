#/bin/bash
# modifty imu noise parameters and recomplie
rm ~/imu.bag ~/allan_variance.csv

catkin_make --pkg vio_data_simulation

rosrun vio_data_simulation vio_data_simulation_node

rosrun allan_variance_ros allan_variance ~ src/allan_variance_ros/config/sim.yaml 

rosrun allan_variance_ros analysis.py --data ~/allan_variance.csv


