package com.cg.healthreminder.controller;

import com.cg.healthreminder.model.FollowUpDietStatusInfo;
import com.cg.healthreminder.services.FollowUpDietStatusInfoServices;
import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;

import org.junit.Assert;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.Mockito;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.web.servlet.WebMvcTest;
import org.springframework.boot.test.mock.mockito.MockBean;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.mock.web.MockHttpServletResponse;
import org.springframework.test.context.junit4.SpringRunner;
import org.springframework.test.web.servlet.MockMvc;
import org.springframework.test.web.servlet.MvcResult;
import org.springframework.test.web.servlet.request.MockMvcRequestBuilders;

import static org.assertj.core.api.Assertions.assertThat;

/**
 * @ParthGoel
 *
 * This is the test class for Follow Up Diet Status Information controller
 */

@RunWith(SpringRunner.class)
@WebMvcTest(value = FollowUpDietStatusInfoController.class)
public class FollowUpDietStatusInfoControllerTest {

	@Autowired
    private MockMvc mockMvc;
	
	@MockBean
    private FollowUpDietStatusInfoServices followUpDietStatusInfoServices;
	
	/**
     * Convert Object into Json String by using Jackson ObjectMapper
     * @param ticket
     * @return
     * @throws JsonProcessingException
     */
	private String converttoJson(Object followUpDietStatusInfo) throws JsonProcessingException {
        ObjectMapper objectMapper = new ObjectMapper();
        return objectMapper.writeValueAsString(followUpDietStatusInfo);
    }
	
	/**
	 * To test create follow up diet status information details  
	 */
	@Test
    public void testCreateDietStatus() throws Exception{
        String URI = "/healthreminder/create_followup_dietstatus";
        FollowUpDietStatusInfo followUpDietStatusInfo = new FollowUpDietStatusInfo();
        followUpDietStatusInfo.setPatientId(1);
        followUpDietStatusInfo.setDietStatus(true);
		
        String jsonInput = this.converttoJson(followUpDietStatusInfo);

        Mockito.when(followUpDietStatusInfoServices.createDietStatus(Mockito.any(FollowUpDietStatusInfo.class))).thenReturn(followUpDietStatusInfo);
        MvcResult mvcResult = this.mockMvc.perform(MockMvcRequestBuilders.post(URI).accept(MediaType.APPLICATION_JSON).content(jsonInput).contentType(MediaType.APPLICATION_JSON))
                .andReturn();
        MockHttpServletResponse mockHttpServletResponse = mvcResult.getResponse();
        String jsonOutput = mockHttpServletResponse.getContentAsString();
        assertThat(jsonInput).isEqualTo(jsonOutput);
        Assert.assertEquals(HttpStatus.OK.value(), mockHttpServletResponse.getStatus());
    }
	
	/**
	 * To test find follow up diet status information details using id  
	 */
	@Test
    public void testFindDietStatusById() throws Exception{
        String URI = "/healthreminder/followup_dietstatus_find/{patientId}";
        FollowUpDietStatusInfo followUpDietStatusInfo = new FollowUpDietStatusInfo();
        followUpDietStatusInfo.setPatientId(1);
        followUpDietStatusInfo.setDietStatus(true);
		
		String jsonInput = this.converttoJson(followUpDietStatusInfo);

        Mockito.when(followUpDietStatusInfoServices.findDietStatusById(Mockito.anyInt())).thenReturn(followUpDietStatusInfo);
        MvcResult mvcResult = this.mockMvc.perform(MockMvcRequestBuilders.get(URI, 1).accept(MediaType.APPLICATION_JSON))
                .andReturn();
        MockHttpServletResponse mockHttpServletResponse = mvcResult.getResponse();
        String jsonOutput = mockHttpServletResponse.getContentAsString();

        assertThat(jsonInput).isEqualTo(jsonOutput);
    }
	
	/**
	 * To test delete follow up diet status information details using id  
	 */
	@Test
    public void testDeleteDietStatus() throws Exception{
    	String URI = "/healthreminder/delete_dietstatus_by_id/{patientId}";  
    	FollowUpDietStatusInfo followUpDietStatusInfo = new FollowUpDietStatusInfo();
        followUpDietStatusInfo.setPatientId(1);
        followUpDietStatusInfo.setDietStatus(true);

        Mockito.when(followUpDietStatusInfoServices.findDietStatusById(Mockito.anyInt())).thenReturn(followUpDietStatusInfo);
        Mockito.when(followUpDietStatusInfoServices.deleteDietStatus(Mockito.any())).thenReturn(true);
        MvcResult mvcResult = this.mockMvc.perform(MockMvcRequestBuilders.delete(URI,1).accept(MediaType.
        		APPLICATION_JSON)).andReturn();
        MockHttpServletResponse mockHttpServletResponse = mvcResult.getResponse();

        Assert.assertEquals(HttpStatus.OK.value(), mockHttpServletResponse.getStatus());

    }
	
	/**
	 * To test update follow up diet status information details using id  
	 */
	@Test
    public void testUpdateDietStatusById() throws Exception{

        String URI = "/healthreminder/followup_dietstatus_update/{patientId}/status/{dietStatus}";
        FollowUpDietStatusInfo followUpDietStatusInfo = new FollowUpDietStatusInfo();
        followUpDietStatusInfo.setPatientId(1);
        followUpDietStatusInfo.setDietStatus(false);
        
        String jsonInput = this.converttoJson(followUpDietStatusInfo);

        Mockito.when(followUpDietStatusInfoServices.updateDietStatusById(Mockito.any(),Mockito.anyBoolean())).thenReturn(followUpDietStatusInfo);
        MvcResult mvcResult = this.mockMvc.perform(MockMvcRequestBuilders.put(URI, 1, true).accept(MediaType.APPLICATION_JSON).content(jsonInput).contentType(MediaType.APPLICATION_JSON))
                .andReturn();
        MockHttpServletResponse mockHttpServletResponse = mvcResult.getResponse();
        String jsonOutput = mockHttpServletResponse.getContentAsString();

        assertThat(jsonInput).isEqualTo(jsonOutput);
    }




	
}
