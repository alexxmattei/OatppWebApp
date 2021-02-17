#include "MyControllerTest.hpp"

#include "../HeaderControllers/ClientController.h"
#include "startapp/MyApiTestClient.hpp"
#include "startapp/TestComponent.hpp"
#include "../DTOs/ClientDto.hpp"

#include "oatpp/web/client/HttpRequestExecutor.hpp"

#include "oatpp-test/web/ClientServerTestRunner.hpp"

void MyClientControllerTest::onRun() {

  TestComponent component;


  oatpp::test::web::ClientServerTestRunner runner;

  
  runner.addController(std::make_shared<ClientController >());

  /* Run test */
  runner.run([this, &runner] {

 
    OATPP_COMPONENT(std::shared_ptr<oatpp::network::ClientConnectionProvider>, clientConnectionProvider);


    OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, objectMapper);


    auto requestExecutor = oatpp::web::client::HttpRequestExecutor::createShared(clientConnectionProvider);


    auto client = MyApiTestClient::createShared(requestExecutor, objectMapper);


    auto response = client->getRoot();


    OATPP_ASSERT(response->getStatusCode() == 200);


    auto message = response->readBodyToDto<oatpp::Object<ClientDto>>(objectMapper.get());


 
    OATPP_ASSERT(message);
    OATPP_ASSERT(message->statusCode == 200);
    OATPP_ASSERT(message->message =="All registered Users returned successfully" );
    OATPP_ASSERT(message->clientId == 1001);
    OATPP_ASSERT(message->roleId == 1);
    OATPP_ASSERT(message->userName == "Alexandru");
    

  }, std::chrono::minutes(10));

  
  std::this_thread::sleep_for(std::chrono::seconds(1));

}
