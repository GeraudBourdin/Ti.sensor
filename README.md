# ti_sensor_demo_app 

Demo project for the all in one Titanium sensor module. (Android only).


## List of avaliable sensors : 

- TYPE_ACCELEROMETER : 
				Measures the acceleration force in m/s2 that is applied to a device on all three physical axes (x, y, and z), including the force of gravity.
				Common Uses : Motion detection (shake, tilt, etc.).

- TYPE_AMBIENT_TEMPERATURE :
				Measures the ambient room temperature in degrees Celsius (°C).
				Common Uses : Monitoring air temperatures.						

- TYPE_GRAVITY :
				Measures the force of gravity in m/s2 that is applied to a device on all three physical axes (x, y, z).
				Common Uses : Motion detection (shake, tilt, etc.).
					
- TYPE_GYROSCOPE : 	
				Measures a device's rate of rotation in rad/s around each of the three physical axes (x, y, and z).
				Common Uses : Rotation detection (spin, turn, etc.).				

- TYPE_LIGHT : 
				Measures the ambient light level (illumination) in lx.
				Common Uses : Controlling screen brightness.
				
- TYPE_LINEAR_ACCELERATION : 
				Measures the acceleration force in m/s2 that is applied to a device on all three physical axes (x, y, and z), excluding the force of gravity.
				Common Uses : Monitoring acceleration along a single axis.				

- TYPE_MAGNETIC_FIELD : 
				Measures the ambient geomagnetic field for all three physical axes (x, y, z) in μT.
				Common Uses : Creating a compass.
				
- TYPE_ORIENTATION :
				Measures degrees of rotation that a device makes around all three physical axes (x, y, z). As of API level 3 you can obtain the inclination matrix and rotation matrix for a device by using the gravity sensor and the geomagnetic field sensor in conjunction with the getRotationMatrix() method.		
				Common Uses : Determining device position.

- TYPE_PRESSURE : 
				Measures the ambient air pressure in hPa or mbar.
				Common Uses : Monitoring air pressure changes.
				
- TYPE_PROXIMITY :
				Measures the proximity of an object in cm relative to the view screen of a device. This sensor is typically used to determine whether a handset is being held up to a person's ear.
				Common Uses : Phone position during a call.		

- TYPE_RELATIVE_HUMIDITY :
				Measures the relative ambient humidity in percent (%).
				Common Uses : Monitoring dewpoint, absolute, and relative humidity.
				
- TYPE_ROTATION_VECTOR : 
				Measures the orientation of a device by providing the three elements of the device's rotation vector.			
				Common Uses : Motion detection and rotation detection.
																				
- TYPE_GEOMAGNETIC_ROTATION_VECTOR
- TYPE_GYROSCOPE_UNCALIBRATED
- TYPE_LINEAR_ACCELERATION
- TYPE_MAGNETIC_FIELD_UNCALIBRATED
- TYPE_SIGNIFICANT_MOTION
- TYPE_STEP_COUNTER
- TYPE_STEP_DETECTOR
- TYPE_GAME_ROTATION_VECTOR: untested.
- TYPE_HEART_RATE : not in API 19, to enabled it, fork, uncomment and compile https://github.com/GeraudBourdin/ti_sensor with API 21.


--------------------------------------------------------------

## Usage : 
```javascript
// Import it into your mobile project and add it to your controller :

var sensor = require('com.geraudbourdin.sensor');

Get list of sensors avaliable on your mobile :

var sensorList = sensor.getSensorList(sensor.TYPE_ALL);

// it return list of constant sensors. 
// Just test if sensor is sensor you need is avaliable :

var sensorsCallback = function(e) {
	if(e.sType == sensor.TYPE_ACCELEROMETER){
		// do stuff with your datas. (see demo app for complete usage and examples).
	}
};
for (i in sensorList){
	if( typeof  sensorsId[sensorList[i]] === 'undefined' ){
		continue;
	}
	if(sensorList[i] == sensor.TYPE_ACCELEROMETER){
		// do your stuff like enable it before set event.
		sensor.setSensor(sensor.TYPE_ACCELEROMETER);
		// In JS don't forget to set your function callback before your event !
		sensor.addEventListener('update', sensorsCallback);
	}
}

Ti.Android.currentActivity.addEventListener('pause', function(e) {
	Ti.API.info("removing sensorsCallback on pause");
	sensor.removeEventListener('update', sensorsCallback);
});
Ti.Android.currentActivity.addEventListener('resume', function(e) {
	Ti.API.info("adding sensorsCallback on resume");
	sensor.addEventListener('update', sensorsCallback);
});
```

### List of constants: 
```javascript
	sensor.TYPE_ACCELEROMETER
	sensor.TYPE_AMBIENT_TEMPERATURE
	sensor.TYPE_GAME_ROTATION_VECTOR
	sensor.TYPE_GEOMAGNETIC_ROTATION_VECTOR
	sensor.TYPE_GRAVITY
	sensor.TYPE_GYROSCOPE
	sensor.TYPE_GYROSCOPE_UNCALIBRATED
	sensor.TYPE_LIGHT
	sensor.TYPE_LINEAR_ACCELERATION
	sensor.TYPE_MAGNETIC_FIELD
	sensor.TYPE_MAGNETIC_FIELD_UNCALIBRATED
	sensor.TYPE_ORIENTATION
	sensor.TYPE_PRESSURE
	sensor.TYPE_PROXIMITY
	sensor.TYPE_RELATIVE_HUMIDITY
	sensor.TYPE_ROTATION_VECTOR
	sensor.TYPE_SIGNIFICANT_MOTION
	sensor.TYPE_STEP_COUNTER
	sensor.TYPE_STEP_DETECTOR
	//sensorsId[sensor.TYPE_HEART_RATE (have to compile module with api 21 to use it).
	
	sensor.SCREEN_BRIGHTNESS_MODE_MANUAL
	sensor.SCREEN_BRIGHTNESS_MODE_AUTOMATIC
```

## functions : 

### get full list of sensors :
```javascript
 	sensor.getSensorList(sensor.TYPE_ALL);
```
###get infos for a specific sensor type :

```javascript 
	sensor.getSensorInfos(sensor.TYPE_ACCELEROMETER);	
	
	//return array  : 
		var infos = sensor.getSensorInfos(type);
		$.name.text = infos['name'];
		$.constant.text = infos['constant'];
		$.version.text = infos['version'];
		$.resolution.text = infos['resolution'];
		$.power.text = infos['power'];
		$.vendor.text = infos['vendor'];
		$.maximumRange.text = infos['maximumRange'];
		$.minDelay.text = infos['minDelay'];
```		

###get the current brightness mode :
```javascript 
	sensor.getBrightnessMode();
	// return sensor.SCREEN_BRIGHTNESS_MODE_MANUAL or sensor.SCREEN_BRIGHTNESS_MODE_AUTOMATIC
```	

###set the current brightness mode :
```javascript 
	// accept sensor.SCREEN_BRIGHTNESS_MODE_MANUAL or sensor.SCREEN_BRIGHTNESS_MODE_AUTOMATIC
	sensor.setBrightnessMode(sensor.SCREEN_BRIGHTNESS_MODE_MANUAL);
```	

###get the current screen brightness value (between 0 AND 255) :
```javascript 
	sensor.getScreenBrightness();
```	

###set the screen brightness value (between 0 AND 255) :
```javascript 
	sensor.setScreenBrightness(255);
```	
		
### Return values for differents types : 
	
#### TYPE_ACCELEROMETER : 
     All values are in SI units (m/s^2)
		e.x: Acceleration minus Gx on the x-axis filtered with a meanFilter to reduce noize and smooth the sensor inputs.
		e.y: Acceleration minus Gy on the y-axis filtered with a meanFilter to reduce noize and smooth the sensor inputs.
		e.z: Acceleration minus Gz on the z-axis filtered with a meanFilter to reduce noize and smooth the sensor inputs.
		
		e.linearAccelerationX : same as e.x without gravity as described on android documentation : http://developer.android.com/reference/android/hardware/SensorEvent.html#values
		e.linearAccelerationY : same as e.y without gravity as described on android documentation : http://developer.android.com/reference/android/hardware/SensorEvent.html#values
		e.linearAccelerationZ : same as e.z without gravity as described on android documentation : http://developer.android.com/reference/android/hardware/SensorEvent.html#values
		


#### TYPE_MAGNETIC_FIELD : 
		All values are in micro-Tesla (uT) and measure the ambient magnetic field in the X, Y and Z axis filtered with a meanFilter to reduce noize and smooth the sensor inputs.
			e.x : in micro-Tesla (uT) and measure the ambient magnetic field in the X axis.
			e.y : in micro-Tesla (uT) and measure the ambient magnetic field in the Y axis.
			e.z : in micro-Tesla (uT) and measure the ambient magnetic field in the Z axis.
			e.magnetometer : ready to use value for a magnetometer app (metal detector) in micro-Tesla (uT).
			
		If used in combination with the TYPE_ACCELEROMETER, extra values are provided :
			e.compassRotation : ready to use value for a compass app. Get the offset degree for magnetic orientation (see demo app for more info on this value).
		
		If you only needs azimuth pitch an roll values consider using Twisti module (https://github.com/appcelerator-developer-relations/Forging-Titanium/tree/master/ep-014/Twisti).
		Azimuth (degrees of rotation around the z axis). This is the angle between magnetic north and the device's y axis. For example, if the device's y axis is aligned with magnetic north this value is 0, and if the device's y axis is pointing south this value is 180. Likewise, when the y axis is pointing east this value is 90 and when it is pointing west this value is 270.
		Pitch (degrees of rotation around the x axis). This value is positive when the positive z axis rotates toward the positive y axis, and it is negative when the positive z axis rotates toward the negative y axis. The range of values is 180 degrees to -180 degrees.
		Roll (degrees of rotation around the y axis). This value is positive when the positive z axis rotates toward the positive x axis, and it is negative when the positive z axis rotates toward the negative x axis. The range of values is 90 degrees to -90 degrees.
			e.azimuth : values returned from the getRotationMatrix, remapCoordinateSystem, and getOrientation function from the android lib. (See http://www.appcelerator.com/blog/2011/11/forging-titanium-episode-15-twisti-part-2-3d-with-three-js/ for more info)
			e.pitch : values returned from the getRotationMatrix, remapCoordinateSystem and getOrientation function from the android lib. (See http://www.appcelerator.com/blog/2011/11/forging-titanium-episode-15-twisti-part-2-3d-with-three-js/ for more info)
			e.roll : values returned from the getRotationMatrix, remapCoordinateSystem and getOrientation function from the android lib. (See http://www.appcelerator.com/blog/2011/11/forging-titanium-episode-15-twisti-part-2-3d-with-three-js/ for more info)

#### TYPE_AMBIENT_TEMPERATURE :
		Ambient (room) temperature
			e.celcius : ambient (room) temperature in degree Celsius.
			e.fahrenheit : ambient (room) temperature in degree Fahrenheit.
				

#### TYPE_GAME_ROTATION_VECTOR :
		Identical to TYPE_ROTATION_VECTOR except that it doesn't use the geomagnetic field. Therefore the Y axis doesn't point north, but instead to some other reference, that reference is allowed to drift by the same order of magnitude as the gyroscope drift around the Z axis.
		In the ideal case, a phone rotated and returning to the same real-world orientation will report the same game rotation vector (without using the earth's geomagnetic field). However, the orientation may drift somewhat over time. This sensor will not have the estimated heading accuracy value.
			e.x : rotation vector component along the x axis. x*sin(θ/2).
			e.y : rotation vector component along the y axis. y*sin(θ/2).
			e.z : rotation vector component along the z axis. z*sin(θ/2).
			e.cos:  cos(θ/2)


#### TYPE_GEOMAGNETIC_ROTATION_VECTOR : 
		The geomagnetic rotation vector sensor is similar to the Rotation Vector Sensor, but it uses a magnetometer instead of a gyroscope. The accuracy of this sensor is lower than the normal rotation vector sensor, but the power consumption is reduced. Only use this sensor if you want to collect some rotation information in the background without draining too much battery. This sensor is most useful when used in conjunction with batching.
			e.x : rotation vector component along the x axis. x*sin(θ/2).
			e.y : rotation vector component along the y axis. y*sin(θ/2).
			e.z : rotation vector component along the z axis. z*sin(θ/2).

#### TYPE_GRAVITY : 
		A three dimensional vector indicating the direction and magnitude of gravity. Units are m/s^2. The coordinate system is the same as is used by the acceleration sensor.
			e.x 
			e.y  
			e.z 
			

#### TYPE_GYROSCOPE : 
		All values are in radians/second and measure the rate of rotation around the device's local X, Y and Z axis. The coordinate system is the same as is used for the acceleration sensor. Rotation is positive in the counter-clockwise direction. That is, an observer looking from some positive location on the x, y or z axis at a device positioned on the origin would report positive rotation if the device appeared to be rotating counter clockwise. Note that this is the standard mathematical definition of positive rotation and does not agree with the definition of roll given earlier.
			e.x : Angular speed around the x-axis
			e.y : Angular speed around the y-axis
			e.z : Angular speed around the z-axis	
			
		Additionnal values from the android documentation that are not fully explained (see http://developer.android.com/reference/android/hardware/SensorEvent.html#values for more infos ) : 
		Typically the output of the gyroscope is integrated over time to calculate a rotation describing the change of angles over the timestep.
			e.radianX : updated rotation around the x-axis in radian.
			e.radianY : updated rotation around the y-axis in radian.
			e.radianZ : updated rotation around the z-axis in radian.	
			e.degreesX : updated rotation around the x-axis in degrees.
			e.degreesY : updated rotation around the y-axis in degrees.
			e.degreesZ : updated rotation around the z-axis in degrees.	
	
			
#### TYPE_GYROSCOPE_UNCALIBRATED :
		All values are in radians/second and measure the rate of rotation around the device's local X, Y and Z axis. The coordinate system is the same as is used for the acceleration sensor. Rotation is positive in the counter-clockwise direction. That is, an observer looking from some positive location on the x, y or z axis at a device positioned on the origin would report positive rotation if the device appeared to be rotating counter clockwise. Note that this is the standard mathematical definition of positive rotation and does not agree with the definition of roll given earlier.
			e.x : Angular speed around the x-axis
			e.y : Angular speed around the y-axis
			e.z : Angular speed around the z-axis	



#### TYPE_HEART_RATE : 
		Heart rate monitor (not tested).
			e.rate : heart rate int.
		
		
		
#### TYPE_LIGHT : 
		Ambient light level in SI lux units
			e.lux : Ambient light level.
			
			
	
#### TYPE_LINEAR_ACCELERATION : 
		A three dimensional vector indicating acceleration along each device axis, not including gravity. All values have units of m/s^2. The coordinate system is the same as is used by the acceleration sensor.
			e.x : Acceleration around the x-axis
			e.y : Acceleration around the y-axis
			e.z : Acceleration around the z-axis	
			

#### TYPE_MAGNETIC_FIELD_UNCALIBRATED :
		Similar to TYPE_MAGNETIC_FIELD, but the hard iron calibration is reported separately instead of being included in the measurement. Factory calibration and temperature compensation will still be applied to the "uncalibrated" measurement. Assumptions that the magnetic field is due to the Earth's poles is avoided.
		
		x_uncalib, y_uncalib, z_uncalib are the measured magnetic field in X, Y, Z axes. Soft iron and temperature calibrations are applied. But the hard iron calibration is not applied. The values are in micro-Tesla (uT).
			e.x_uncalib
			e.y_uncalib
			e.z_uncalib
		x_bias, y_bias, z_bias give the iron bias estimated in X, Y, Z axes. Each field is a component of the estimated hard iron calibration. The values are in micro-Tesla (uT).
			e.x_bias
			e.y_bias
			e.z_bias
		
			
#### TYPE_PROXIMITY :
		Proximity sensor distance measured in centimeters
		Note: Some proximity sensors only support a binary near or far measurement. In this case, the sensor should report its maximum range value in the far state and a lesser value in the near state.
			e.cm : distance between phone and obstacle in centimeter.
			

#### TYPE_RELATIVE_HUMIDITY : 
			e.percent : Relative ambient air humidity in percent.
			

#### TYPE_ROTATION_VECTOR
		The rotation vector represents the orientation of the device as a combination of an angle and an axis, in which the device has rotated through an angle θ around an axis <x, y, z>.
		The three elements of the rotation vector are <x*sin(θ/2), y*sin(θ/2), z*sin(θ/2)>, such that the magnitude of the rotation vector is equal to sin(θ/2), and the direction of the rotation vector is equal to the direction of the axis of rotation.
		The three elements of the rotation vector are equal to the last three components of a unit quaternion <cos(θ/2), x*sin(θ/2), y*sin(θ/2), z*sin(θ/2)>.
		Elements of the rotation vector are unitless. The x,y, and z axis are defined in the same way as the acceleration sensor.
		The reference coordinate system is defined as a direct orthonormal basis, where:
		X is defined as the vector product Y.Z (It is tangential to the ground at the device's current location and roughly points East).
		Y is tangential to the ground at the device's current location and points towards magnetic north.
		Z points towards the sky and is perpendicular to the ground.
		
			e.x : rotation vector component along the x axis. x*sin(θ/2).
			e.y : rotation vector component along the y axis. y*sin(θ/2).
			e.z : rotation vector component along the z axis. z*sin(θ/2).
			e.cos:  cos(θ/2)
			e.headingAccuracy estimated heading Accuracy (in radians) (-1 if unavailable).
			
#### TYPE_SIGNIFICANT_MOTION : 
		e.motion : 1.0 when the sensor triggers. 1.0 is the only allowed value.
		
		
#### TYPE_STEP_COUNTER
	This sensor also triggers an event upon each detected step, but instead delivers the total accumulated number of steps since this sensor was first registered by an app.
		e.val :  returns the number of steps taken by the user since the last reboot while activated.
		e.count :  returns the number of steps taken by the user since the event is registered.

#### TYPE_STEP_DETECTOR
	This sensor triggers an event each time the user takes a step. Upon each user step, this sensor delivers an event with a value of 1.0 and a timestamp indicating when the step occurred.
		e.count : returns the number of steps taken by the user since the event is registered. 		

	Be aware that these two step sensors don't always deliver the same results. The TYPE_STEP_COUNTER events occur with a higher latency than those from TYPE_STEP_DETECTOR, but that's because the TYPE_STEP_COUNTER algorithm does more processing to eliminate false positives. So the TYPE_STEP_COUNTER may be slower to deliver events, but its results should be more accurate.


#### TYPE_ORIENTATION :
	All values are angles in degrees. Note: This definition is different from yaw, pitch and roll used in aviation where the X axis is along the long side of the plane (tail to nose).
		e.orientation : Azimuth, angle between the magnetic north direction and the y-axis, around the z-axis (0 to 359). 0=North, 90=East, 180=South, 270=West.
		e.pitch : Pitch, rotation around x-axis (-180 to 180), with positive values when the z-axis moves toward the y-axis.
		e.roll : Roll, rotation around the x-axis (-90 to 90) increasing as the device moves clockwise.
