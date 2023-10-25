#!/bin/bash

chmod +x fork_1.sh
chmod +x fork_2.sh
chmod +x fork_3.sh
cd ~
mkdir Dir1_1_2
mkdir Dir2_1_2
mkdir Dir3_1_2
cp -r linux-5.19.9 Dir1_1_2
cp -r linux-5.19.9 Dir2_1_2
cp -r linux-5.19.9 Dir3_1_2
cp -r config-rev-9-gold Dir1_1_2/linux-5.19.9
cp -r config-rev-9-gold Dir2_1_2/linux-5.19.9
cp -r config-rev-9-gold Dir3_1_2/linux-5.19.9
cd Dir1_1_2
cd linux-5.19.9
cp config-rev-9-gold .config
cd ~
cd Dir2_1_2
cd linux-5.19.9
cp config-rev-9-gold .config
cd ~
cd Dir3_1_2
cd linux-5.19.9
cp config-rev-9-gold .config
cd ~
