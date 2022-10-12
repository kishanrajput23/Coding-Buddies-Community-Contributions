/**
 * @SayantanDas
 * 
 * This is the Interface for AppointmentSlots representing the various services provided.
*/
package com.cg.healthreminder.services;

import java.util.List;

import com.cg.healthreminder.exception.AllCustomException;
import com.cg.healthreminder.model.AppointmentSlots;


public interface AppointmentSlotsServices {
	List<AppointmentSlots> getAllSlots();
	AppointmentSlots createAppointmentSlot(AppointmentSlots as);
	AppointmentSlots deleteAppointmentSlot(AppointmentSlots as) throws AllCustomException;
	
	
}
