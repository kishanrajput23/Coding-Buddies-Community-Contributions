/**
 * @SayantanDas
 * 
 * This is the ControllerClass for AppointmentDetails 
*/
package com.cg.healthreminder.controller;

import javax.validation.Valid;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.cg.healthreminder.exception.AllCustomException;
import com.cg.healthreminder.model.AppointmentDetails;
import com.cg.healthreminder.services.AppointmentDetailsServices;


@Validated
@RestController
@CrossOrigin(origins = "*")
@RequestMapping("/healthreminder")
public class AppointmentDetailsController{
	
	    @Autowired
	    private AppointmentDetailsServices appointmentDetailService;
	    private static final Logger logger=LogManager.getLogger( AppointmentDetailsController.class);
	    
	    /**
	     * To find Appointments by patient Id.
	     * @param patientId
	     * throws AllCustomException if not found
	    */
	    @GetMapping("/findAppointmentByPatId/{patientId}")
	    public AppointmentDetails findAppointmentDetailsByPatientId(@Valid@PathVariable int patientId) throws AllCustomException{
	    	logger.info("In controller class of finding appointment by patient ids ........"); 
	    	
	      	return appointmentDetailService.findAppointmentDetailByPatientId(patientId);
	    }
	    

	    /**
	     * To find Appointments by doctor Id.
	     * @param doctorId
	     * throws AllCustomException if not found
	    */
	    @GetMapping("/findAppointmentByDocId/{doctorId}")
	    public AppointmentDetails findAppointmentDetailsByDoctorId(@Valid@PathVariable int doctorId) throws AllCustomException{
	    	logger.info("In controller class of finding appointment by doctor ids ........");
	    	
	    	return appointmentDetailService.findAppointmentDetailByDoctorId(doctorId);
	    }
	    
	    
	    /**
	     * To create an Appointment
	     * @param Json Body
	     * 
	    */
	    @PostMapping("/createAppointment")
	    public AppointmentDetails createTicket(@Valid@RequestBody AppointmentDetails apd){
	    	logger.info("In controller class of creating appointment ........");
	    	
	    	return appointmentDetailService.createAppointment(apd);
	    }
	    
	    
	    /**
	     * To delete an Appointment by Patient Id
	     * @param patientId
	     * throws AllCustomException if not found
	    */
	    @DeleteMapping("/deleteAppointmentByPatId/{patientId}")
	    public AppointmentDetails deleteAppointmentByPatientId(@Valid@PathVariable int patientId) throws AllCustomException{
	    	logger.info("In controller class of deleting appointment by patient ids ........");
	    	
	    	return appointmentDetailService.deleteAppointmentByPatientId(patientId);
	    }


	    /**
	     * To delete an Appointment by Doctor Id
	     * @param DoctorId
	     * throws AllCustomException if not found
	    */
	    @DeleteMapping("/deleteAppointmentByDocId/{doctorId}")
	    public AppointmentDetails deleteAppointmentByDoctorId(@Valid@PathVariable int doctorId) throws AllCustomException{
	    	logger.info("In controller class of deleting appointment by doctor ids ........");
	    	
	    	return appointmentDetailService.deleteAppointmentByDoctorId(doctorId);
	    }
}
