/**
 * @SayantanDas
 * 
 * This is the Service Class for AppointmentDetails.
*/
package com.cg.healthreminder.services.impl;


import java.util.List;
import java.util.Optional;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.springframework.beans.factory.annotation.Autowired;

import com.cg.healthreminder.dao.AppointmentSlotsJpaDao;
import com.cg.healthreminder.exception.AllCustomException;
import com.cg.healthreminder.model.AppointmentSlots;
import com.cg.healthreminder.services.AppointmentSlotsServices;
import org.springframework.stereotype.Service;

import javax.transaction.Transactional;
@Service
@Transactional
public class AppointmentSlotServicesImpl implements AppointmentSlotsServices {
	
	@Autowired
    private AppointmentSlotsJpaDao appointmentSlotsJpaDao;
	private static final Logger logger=LogManager.getLogger(AppointmentSlotServicesImpl.class);
	
	
	/**
	 * 
	 * To get all available appointment slots.
	*/
	public List<AppointmentSlots> getAllSlots(){
		logger.info("Sending all SLots ........"); 
		
		return appointmentSlotsJpaDao.findAll();
	}
	
	
	
	/**
	 * 
	 * To create an Appointment SLot
	*/
	public AppointmentSlots createAppointmentSlot(AppointmentSlots as) {
		logger.info("Creating Appointment SLot ........");
		
		return  appointmentSlotsJpaDao.save(as);
	}
	
	
	/**
	 * 
	 * To delete an Appointment SLot
	*/
	public AppointmentSlots deleteAppointmentSlot(AppointmentSlots as) throws AllCustomException {
		logger.info("Deleting appointment SLot ........");
		
		Optional<AppointmentSlots> a = appointmentSlotsJpaDao.findById(as.getPk());
		AppointmentSlots aslot=null;
		if(a.isPresent()) {
			 aslot= a.get();
			 appointmentSlotsJpaDao.delete(aslot); 
		}
		else
		{
			throw new AllCustomException("Appointment Slot not found");
		}
		return aslot;
    }
}
