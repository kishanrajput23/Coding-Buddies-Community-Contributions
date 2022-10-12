/**
 * @SayantanDas
 * 
 * This is the ControllerClass for AppointmentSlots
*/


package com.cg.healthreminder.controller;

import java.util.List;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.cg.healthreminder.exception.AllCustomException;
import com.cg.healthreminder.model.AppointmentSlots;
import com.cg.healthreminder.services.AppointmentSlotsServices;

@RestController
@RequestMapping("/healthreminder")
@CrossOrigin(origins = "*")
public class AppointmentSlotsController {
	 	@Autowired
	    private AppointmentSlotsServices appointmentSlotService;
	 	private static final Logger logger=LogManager.getLogger(AppointmentSlotsController.class);
	 	
	 	
	    /**
	     * To Get all the available slots.
	     * 
	    */
	    @GetMapping("/getAllSlots")
	    public List<AppointmentSlots> getAllSlots(){
	    	logger.info("In controller class of geting all slots ........"); 
	    	
	    	return appointmentSlotService.getAllSlots();
	    }

	    
	    /**
	     * To create an appointment slot
	     * @param Json Body
	     * 
	    */
	    @PostMapping("/createAppointmentSlot")
	    public AppointmentSlots createTicket(@RequestBody AppointmentSlots aps){
	    	logger.info("In controller class of creating appointment slot ........"); 
	    	
	    	return appointmentSlotService.createAppointmentSlot(aps);
	    }

	    
	    /**
	     * To delete an Appointment Slot
	     * @param Json Body
	     * throws AllCustomException if not found
	    */
	    @DeleteMapping("/deleteAppointmentSlot")
	    public AppointmentSlots deleteAppointmentSlot(@RequestBody AppointmentSlots aps)  throws AllCustomException{
	    	logger.info("In controller class of deleting appointment slot ........"); 
	    	
	    	return appointmentSlotService.deleteAppointmentSlot(aps);
	    }

}
