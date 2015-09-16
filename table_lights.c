// copyright (c), KIPR 2014

void table_lights(int lports[], int pcnt, int onoff)  // turn on lights (motor ports and digital ports)
{	
	int i;
	for(i=0;i<pcnt;i++) {
		set_digital_value(lports[i],onoff);
	}
	if(onoff) {
		for(i=0;i<4;i++) {
			fd(i);
		}
	}
	else {
		ao();
	}
}

