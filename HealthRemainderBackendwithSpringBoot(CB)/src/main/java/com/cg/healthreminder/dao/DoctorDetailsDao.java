/**
 * @Ankit Banerjee
 *
 * This is the DAO class for Doctor Details
 */
package com.cg.healthreminder.dao;

import org.springframework.data.jpa.repository.JpaRepository;

import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.query.Param;

import com.cg.healthreminder.model.DoctorDetails;
/**
*
* Doctor Details Dao Class
*/
public interface DoctorDetailsDao extends JpaRepository<DoctorDetails,Integer>{
	
	@Query("select d from DoctorDetails d where d.doctorId=:doctorId")
	DoctorDetails findDoctorById(@Param("doctorId")Integer doctorId);
	
	@Query("select d from DoctorDetails d where d.doctorSpec=:doctorSpec")
	DoctorDetails findDoctorBySpec(@Param("doctorSpec")String doctorSpec);
	
	
}
