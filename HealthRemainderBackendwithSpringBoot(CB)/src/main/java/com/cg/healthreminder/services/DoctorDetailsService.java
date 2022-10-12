/**
 * @Ankit Banerjee
 *
 * Interface for DoctorDetails which contains various services provided.
 */
package com.cg.healthreminder.services;

import com.cg.healthreminder.exception.AllCustomException;
import com.cg.healthreminder.model.DoctorDetails;

public interface DoctorDetailsService {

	DoctorDetails findDoctorById(Integer id)  throws AllCustomException;
	DoctorDetails findDoctorBySpec(String doctorSpec)  throws AllCustomException;
	Iterable<DoctorDetails> getAllDoctorDetails()  throws AllCustomException;
	public DoctorDetails updateDoctorById(Integer doctorId,String doctorName,boolean verfStatus,  String doctorCertFile,  String doctorSpec) throws AllCustomException;
	DoctorDetails deleteDoctorById(Integer id)  throws AllCustomException;
	DoctorDetails createDoctor(DoctorDetails doctorDetails);
	

	
	
}
