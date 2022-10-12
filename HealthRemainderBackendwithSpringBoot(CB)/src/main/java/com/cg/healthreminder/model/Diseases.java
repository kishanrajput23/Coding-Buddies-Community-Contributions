package com.cg.healthreminder.model;

import javax.persistence.*;
import javax.validation.constraints.Min;
import javax.validation.constraints.NotNull;
import javax.validation.constraints.Pattern;

/**
 * @ShaniaDalal
 * 
 * This is the Model class for Diseases
 */

@Entity 
@Table(name="diseases_info")  //--> table to store all information on diseases
public class Diseases {
	
	@Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	@Min(1)
	private Integer diseaseId;
	
	@Column(name = "dis_name")
	@NotNull
	@Pattern(regexp = ".*[a-zA-Z]+.*",message="Please enter atleast one Alphabet")
	private String diseaseName;
	
	@Column(name = "dis_info")
	@NotNull
	@Pattern(regexp = ".*[a-zA-Z]+.*",message="Please enter atleast one Alphabet")
	private String diseaseInfo;
	
	@Column(name = "dis_keys")
	@NotNull
	@Pattern(regexp = ".*[a-zA-Z]+.*",message="Please enter atleast one Alphabet")
	private String diseaseKeys;
	
	public Integer getDiseaseId() {
		return diseaseId;
	}
	
	public void setDiseaseId(Integer diseaseId) {
		this.diseaseId = diseaseId;
	}
	
	public String getDiseaseName() {
		return diseaseName;
	}
	
	public void setDiseaseName(String diseaseName) {
		this.diseaseName = diseaseName;
	}
	
	public String getDiseaseInfo() {
		return diseaseInfo;
	}
	
	public void setDiseaseInfo(String diseaseInfo) {
		this.diseaseInfo = diseaseInfo;
	}
	
	public String getDiseaseKeys() {
		return diseaseKeys;
	}
	
	public void setDiseaseKeys(String diseaseKeys) {
		this.diseaseKeys = diseaseKeys;
	}
	
	@Override
	public String toString() {
		return "Diseases [diseaseId=" + diseaseId + ", diseaseName=" + diseaseName + ", diseaseInfo=" + diseaseInfo
				+ ", diseaseKeys=" + diseaseKeys + "]";
	}
	
	
}