package com.cg.healthreminder.controller;

import com.cg.healthreminder.model.DietInfo;
import com.cg.healthreminder.services.DietInfoServices;
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
 * This is the test class for Diet Information controller
 */

@RunWith(SpringRunner.class)
@WebMvcTest(value = DietInfoController.class)
public class DietInfoControllerTest {

	@Autowired
    private MockMvc mockMvc;
	
	@MockBean
    private DietInfoServices dietInfoService;
	
	/**
     * Convert Object into Json String by using Jackson ObjectMapper
     * @param ticket
     * @return
     * @throws JsonProcessingException
     */
	private String converttoJson(Object dietInfo) throws JsonProcessingException {
        ObjectMapper objectMapper = new ObjectMapper();
        return objectMapper.writeValueAsString(dietInfo);
    }
	
	/**
	 * To test create diet information details  
	 */
	@Test
    public void testCreateDiet() throws Exception{
        String URI = "/healthreminder/create_diet";
        DietInfo dietInfo = new DietInfo();
        dietInfo.setBmiValue(1);
        dietInfo.setDiet("pizza");
		
        String jsonInput = this.converttoJson(dietInfo);

        Mockito.when(dietInfoService.createDiet(Mockito.any(DietInfo.class))).thenReturn(dietInfo);
        MvcResult mvcResult = this.mockMvc.perform(MockMvcRequestBuilders.post(URI).accept(MediaType.APPLICATION_JSON).content(jsonInput).contentType(MediaType.APPLICATION_JSON))
                .andReturn();
        MockHttpServletResponse mockHttpServletResponse = mvcResult.getResponse();
        String jsonOutput = mockHttpServletResponse.getContentAsString();
        assertThat(jsonInput).isEqualTo(jsonOutput);
        Assert.assertEquals(HttpStatus.OK.value(), mockHttpServletResponse.getStatus());
    }
	
	/**
	 * To test find diet information details using id  
	 */
	@Test
    public void testFindDietByBMI() throws Exception{
        String URI = "/healthreminder/diet_info_find/{bmi}";
        DietInfo dietInfo = new DietInfo();
        dietInfo.setBmiValue(1);
        dietInfo.setDiet("pizza");
		
		String jsonInput = this.converttoJson(dietInfo);

        Mockito.when(dietInfoService.findDietByBMI(Mockito.anyInt())).thenReturn(dietInfo);
        MvcResult mvcResult = this.mockMvc.perform(MockMvcRequestBuilders.get(URI, 4).accept(MediaType.APPLICATION_JSON))
                .andReturn();
        MockHttpServletResponse mockHttpServletResponse = mvcResult.getResponse();
        String jsonOutput = mockHttpServletResponse.getContentAsString();

        assertThat(jsonInput).isEqualTo(jsonOutput);
    }
	
	/**
	 * To test delete diet information details using id  
	 */
	@Test
    public void testDeleteDietByBMI() throws Exception{
    	String URI = "/healthreminder/delete_diet_by_bmi/{bmiValue}";  
    	DietInfo dietInfo = new DietInfo();
    	dietInfo.setBmiValue(1);
        dietInfo.setDiet("pizza");

        Mockito.when(dietInfoService.findDietByBMI(Mockito.anyInt())).thenReturn(dietInfo);
        Mockito.when(dietInfoService.deleteDietByBMI(Mockito.any())).thenReturn(true);
        MvcResult mvcResult = this.mockMvc.perform(MockMvcRequestBuilders.delete(URI,1).accept(MediaType.
        		APPLICATION_JSON)).andReturn();
        MockHttpServletResponse mockHttpServletResponse = mvcResult.getResponse();

        Assert.assertEquals(HttpStatus.OK.value(), mockHttpServletResponse.getStatus());

    }
	
	/**
	 * To test update diet information details using id  
	 */
	@Test
    public void testUpdateDietByBMI() throws Exception{

        String URI = "/healthreminder/diet_info_update/{bmiValue}/info/{dietInformation}";
        DietInfo dietInfo = new DietInfo();
    	dietInfo.setBmiValue(1);
        dietInfo.setDiet("pizza");
        
        String jsonInput = this.converttoJson(dietInfo);

        Mockito.when(dietInfoService.updateDietByBMI(Mockito.any(),Mockito.anyString())).thenReturn(dietInfo);
        MvcResult mvcResult = this.mockMvc.perform(MockMvcRequestBuilders.put(URI, 1, "\"pizza\"").accept(MediaType.APPLICATION_JSON).content(jsonInput).contentType(MediaType.APPLICATION_JSON))
                .andReturn();
        MockHttpServletResponse mockHttpServletResponse = mvcResult.getResponse();
        String jsonOutput = mockHttpServletResponse.getContentAsString();

        assertThat(jsonInput).isEqualTo(jsonOutput);
    }



}
