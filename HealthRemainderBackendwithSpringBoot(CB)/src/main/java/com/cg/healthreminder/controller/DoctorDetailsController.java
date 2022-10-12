/**
 * @Ankit Banerjee
 *
 * This is the Controller class for Doctor Details
 */
package com.cg.healthreminder.controller;

import java.util.List;

import javax.validation.Valid;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.cg.healthreminder.exception.AllCustomException;
import com.cg.healthreminder.model.DoctorDetails;
import com.cg.healthreminder.services.DoctorDetailsService;

@CrossOrigin(origins = "http://localhost:3000")
@RestController
@RequestMapping("/healthreminder")
public class DoctorDetailsController {
	
	@Autowired
    private DoctorDetailsService doctorDetailsService;
	private static final Logger logger=LogManager.getLogger(DoctorDetailsController.class);
	
	/**
	 *
	 * To get all doctor details
	 */
	@GetMapping("/getAllDoctors")
    public List<DoctorDetails> getAllDoctors() throws AllCustomException{
		logger.info("DoctorDetailsController: Retrieve All Doctor details URL........");
		
        return (List<DoctorDetails>) doctorDetailsService.getAllDoctorDetails();
    }
	
	/**
	 *
	 * To get all doctor details using doctor id
	 */
	@GetMapping("/getDoctorById/{doctorId}")
    public DoctorDetails getDoctorById(@PathVariable Integer doctorId) throws AllCustomException{
		logger.info("DoctorDetailsController: Retrieve Doctor details using Doctor Id URL........");
		
        return doctorDetailsService.findDoctorById(doctorId);
    }
	
	/**
	 *
	 * To get all doctor details using doctor specialization
	 */
	@GetMapping("/getDoctorBySpec/{doctorSpec}")
    public DoctorDetails getDoctorBySpec(@PathVariable String doctorSpec) throws AllCustomException{
		logger.info("DoctorDetailsController: Retrieve Doctor details using Doctor Specialization URL........");
		
        return doctorDetailsService.findDoctorBySpec(doctorSpec);
    }
	
	/**
	 *
	 * To update doctor details
	 */
	@PutMapping("/updateDoctorNamebyId/{doctorId}/{doctorName}/{verfStatus}/{doctorCertFile}/{doctorSpec}")
    public DoctorDetails updateDoctorById(@PathVariable Integer doctorId, @PathVariable String doctorName,
    		@PathVariable boolean verfStatus, @PathVariable String doctorCertFile, @PathVariable String doctorSpec) throws AllCustomException{
		logger.info("DoctorDetailsController: Update Doctor details using Doctor Id URL........");
		
		return doctorDetailsService.updateDoctorById(doctorId, doctorName, verfStatus, doctorCertFile, doctorSpec);
    }
	
	/**
	 *
	 * To create doctor details
	 */
	@PostMapping("/createDoctor")
    public DoctorDetails createDoctor(@Valid @RequestBody DoctorDetails doctor){
		logger.info("DoctorDetailsController: Create Doctor details URL........");
		
        return doctorDetailsService.createDoctor(doctor);
    }
	
	/**
	 *
	 * To delete doctor details using doctor id
	 */
	@DeleteMapping("/deleteDoctorById/doctor/{doctorId}")
    public DoctorDetails deleteDoctorById(@PathVariable Integer doctorId) throws AllCustomException{
		logger.info("DoctorDetailsController: Delete Doctor details using Doctor Id URL........");
		
		
        return doctorDetailsService.deleteDoctorById(doctorId);
    }

	
}
