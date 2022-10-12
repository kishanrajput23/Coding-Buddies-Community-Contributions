/**
 * @SayantanDas
 * 
 * This is the Service Class for Doctor Details.
*/

package com.cg.healthreminder.services.impl;


import org.springframework.beans.factory.annotation.Autowired;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import com.cg.healthreminder.dao.DoctorDetailsDao;
import com.cg.healthreminder.exception.AllCustomException;
import com.cg.healthreminder.model.DoctorDetails;
import com.cg.healthreminder.services.DoctorDetailsService;
import org.springframework.stereotype.Service;

import java.util.Optional;

import javax.transaction.Transactional;

@Service
@Transactional
public class DoctorDetailsServiceImpl implements DoctorDetailsService {

	public static final String D_EXCEP = "Doctor Details Not Found";
	
	@Autowired
	private DoctorDetailsDao doctorDetailsDao;
	private static final Logger logger=LogManager.getLogger(DoctorDetailsServiceImpl.class);
	
	/**
	 * 
	 * To find Doctor Details by Doctor Id.
	*/
	@Override
	public DoctorDetails findDoctorById(Integer id) throws AllCustomException
	{
		logger.info("DoctorDetailsServiceImpl: Finding Doctor Details by Doctor Id........");
		
		DoctorDetails ob = doctorDetailsDao.findDoctorById(id);
		if(ob == null) {
			throw new AllCustomException(D_EXCEP);
		}
		
		return ob;
	}
	
	/**
	 * 
	 * To find Doctor Details by Doctor Specialization.
	*/
	@Override
	public DoctorDetails findDoctorBySpec(String doctorSpec) throws AllCustomException
	{
		logger.info("DoctorDetailsServiceImpl: Finding Doctor Details by Doctor Specialization........");
		
		DoctorDetails ob = doctorDetailsDao.findDoctorBySpec(doctorSpec);
		if(ob == null) {
			throw new AllCustomException(D_EXCEP);
		}
		
		return ob;
	}
	
	/**
	 * 
	 * To Get All Doctor Details.
	*/
	@Override
	public Iterable<DoctorDetails> getAllDoctorDetails()
	{
		logger.info("DoctorDetailsServiceImpl: Retreiving All Doctor Details........");
		
		return doctorDetailsDao.findAll();
	}
	
	/**
	 * 
	 * To update Doctor Details by Doctor Id.
	*/
	@Override
	public DoctorDetails updateDoctorById(Integer doctorId,String doctorName,boolean verfStatus,  String doctorCertFile,  String doctorSpec) throws AllCustomException
	{
		logger.info("DoctorDetailsServiceImpl: Updating Doctor Details by Doctor Id........");
		
		Optional<DoctorDetails> doctorDetails = doctorDetailsDao.findById(doctorId);
		DoctorDetails ob = null;
		
		if(doctorDetails.isPresent()) {
			ob = doctorDetails.get();
			ob.setDoctorName(doctorName);
			ob.setVerfStatus(true);
			ob.setDoctorCertFile("Certified");
			ob.setDoctorSpec("Lungs");
		}
		else
		{
			throw new AllCustomException(D_EXCEP);
		}
		
		return doctorDetailsDao.save(ob);
	}
	
	/**
	 * 
	 * To delete Doctor Details by Doctor Id.
	*/
	@Override
	public DoctorDetails deleteDoctorById(Integer id) throws AllCustomException
	{
		logger.info("DoctorDetailsServiceImpl: Deleting Doctor Details by Doctor Id........");
		
		Optional<DoctorDetails> doctorDetails = doctorDetailsDao.findById(id);
		DoctorDetails ob = null;
		
		if(doctorDetails.isPresent())
		{
			ob = doctorDetails.get();
			doctorDetailsDao.delete(ob);
		}
		else
		{
			throw new AllCustomException(D_EXCEP);
		}
		return ob;
	}
	
	/**
	 * 
	 * To create Doctor Details.
	*/
	@Override
	public DoctorDetails createDoctor(DoctorDetails doctorDetails)
	{
		logger.info("DoctorDetailsServiceImpl: Creating Doctor Details........");
		
		return doctorDetailsDao.save(doctorDetails);
	}
	
}
