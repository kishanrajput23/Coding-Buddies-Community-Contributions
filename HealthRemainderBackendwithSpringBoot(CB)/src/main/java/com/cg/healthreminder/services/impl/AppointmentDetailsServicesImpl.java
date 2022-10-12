/**
 * @SayantanDas
 * 
 * This is the Service Class for AppointmentDetails.
*/

package com.cg.healthreminder.services.impl;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.springframework.beans.factory.annotation.Autowired;

import com.cg.healthreminder.dao.AppointmentDetailsJpaDao;
import com.cg.healthreminder.exception.AllCustomException;
import com.cg.healthreminder.model.AppointmentDetails;
import com.cg.healthreminder.services.AppointmentDetailsServices;
import org.springframework.stereotype.Service;

import javax.transaction.Transactional;
@Service
@Transactional
public class AppointmentDetailsServicesImpl implements AppointmentDetailsServices {
	@Autowired
    private AppointmentDetailsJpaDao appointmentDetailsJpaDao;
	private static final Logger logger=LogManager.getLogger(AppointmentDetailsServicesImpl.class);
	
	
	/**
	 * 
	 * To find Appointment by Patient Id.
	*/
	@Override
	public AppointmentDetails findAppointmentDetailByPatientId(int patientId) throws AllCustomException {
		
		logger.info("Finding appointment details by patient Id ........");
		
		AppointmentDetails a= appointmentDetailsJpaDao.findByPatientId(patientId);
		if(a==null) {
			throw new AllCustomException("Appointment not found for the given Patient id");
		}
		return a;
	}
	
	
	/**
	 * 
	 * To find Appointment by Doctor Id.
	*/
	public AppointmentDetails findAppointmentDetailByDoctorId(int doctorId) throws AllCustomException {
		
		logger.info("Finding appointment details by doctor Id ........");
		
		AppointmentDetails a= appointmentDetailsJpaDao.findByDoctorId(doctorId);
		if(a==null) {
			throw new AllCustomException("Appointment not found for the given Doctor id");
		}
		return a;
	}
    
	
	/**
	 * 
	 * To create an Appointment.
	*/
	public AppointmentDetails createAppointment(AppointmentDetails amp){
		logger.info("Creating Appointment ........");
		
		return appointmentDetailsJpaDao.save(amp);
    }
    
	
	/**
	 * 
	 * To delete Appointment by Patient Id.
	*/
	public AppointmentDetails deleteAppointmentByPatientId(int patientId)  throws AllCustomException{
		
		logger.info("Deleting appointment details by patient Id ........");
		AppointmentDetails a= appointmentDetailsJpaDao.findByPatientId(patientId);
		if(a!=null) {
			
			 appointmentDetailsJpaDao.delete(a);
		}
		else {
			throw new AllCustomException("Appointment not found for the given Patient id");
		}
		return a;
    }
	
	
	/**
	 * 
	 * To delete Appointment by Doctor Id.
	*/
    public AppointmentDetails deleteAppointmentByDoctorId(int doctorId) throws AllCustomException {
    	logger.info("Deleting appointment details by doctor Id ........");
    	
    	AppointmentDetails a= appointmentDetailsJpaDao.findByDoctorId(doctorId);
		if(a!=null) {
			
			 appointmentDetailsJpaDao.delete(a);
		}
		else {
			throw new AllCustomException("Appointment not found for the given Doctor id");
		}
		return a;
    }
}
