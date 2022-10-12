/**
 * @AnkitBanerjee
 *
 * This is the Model/Entity class for Doctor Details
 */
package com.cg.healthreminder.model;

import javax.persistence.*;
import javax.validation.constraints.*;

@Entity
@Table(name = "Doctor_Details")
public class DoctorDetails {
	
	public static final String REG = "^[a-zA-Z\s]+$";
	public static final String REG_NUM = "^[a-zA-Z0-9\s]+$";
	
	
	@Override
	public String toString() {
		return "DoctorDetails [doctorId=" + doctorId + ", verfStatus=" + verfStatus + ", doctorName=" + doctorName
				+ ", doctorSpec=" + doctorSpec + ", doctorCertFile=" + doctorCertFile + "]";
	}

	@Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    @Column(name = "doct_id")
    private Integer doctorId;
	
	@NotNull
    @Column(name = "verf_status")
    private boolean verfStatus;
    
	@NotNull
	@Pattern(regexp=REG, message="only alphabets and spaces allowed")
	@Size(min=2, max=30)
    @Column(name = "doc_name")
    private String doctorName;
    
	@NotNull
	@Pattern(regexp=REG, message="only alphabets and spaces allowed")
	@Size(min=2, max=30)
    @Column(name = "doc_spec")
    private String doctorSpec;
    
	@NotNull
	@Pattern(regexp=REG_NUM, message="only alphanumeric letters and spaces allowed")
	@Size(min=2, max=30)
    @Column(name = "certificate_file")
    private String doctorCertFile;

	public Integer getDoctorId() {
		return doctorId;
	}

	public void setDoctorId(Integer doctorId) {
		this.doctorId = doctorId;
	}

	public boolean isVerfStatus() {
		return verfStatus;
	}

	public void setVerfStatus(boolean verfStatus) {
		this.verfStatus = verfStatus;
	}

	public String getDoctorName() {
		return doctorName;
	}

	public void setDoctorName(String doctorName) {
		this.doctorName = doctorName;
	}

	public String getDoctorSpec() {
		return doctorSpec;
	}

	public void setDoctorSpec(String doctorSpec) {
		this.doctorSpec = doctorSpec;
	}

	public String getDoctorCertFile() {
		return doctorCertFile;
	}

	public void setDoctorCertFile(String doctorCertFile) {
		this.doctorCertFile = doctorCertFile;
	}

	
	
	
    
	
}
