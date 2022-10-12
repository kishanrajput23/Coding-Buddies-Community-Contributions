package com.cg.healthreminder;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import com.google.common.base.Predicates;

import springfox.documentation.builders.ApiInfoBuilder;
import springfox.documentation.builders.PathSelectors;
import springfox.documentation.service.ApiInfo;
import springfox.documentation.spi.DocumentationType;
import springfox.documentation.spring.web.plugins.Docket;
import springfox.documentation.swagger2.annotations.EnableSwagger2;

/**
 * @ShaniaDalal
 * 
 * This is the Swagger  Configuration class for Health Reminder Application
 */

@Configuration
@EnableSwagger2
public class HealthReminderSwagger{
	
	@Bean
	public Docket postsApi() {
		return new Docket(DocumentationType.SWAGGER_2).apiInfo(metadata()).select().paths(Predicates.not(PathSelectors.regex("/error"))).build();
	}

	@SuppressWarnings("deprecation")
	private ApiInfo metadata() {
		return new ApiInfoBuilder().title("Health Reminder App").description("API reference guide for developers").termsOfServiceUrl("https://www.team3.com/").contact("Dalal, Shania").version("1.0").build();	
	}
}