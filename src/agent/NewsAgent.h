/**
* Copyright 2017 IBM Corp. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
*/


#ifndef SELF_NEWSAGENT_H
#define SELF_NEWSAGENT_H

#include "IAgent.h"
#include "blackboard/NewsIntent.h"
#include "SelfLib.h"

class SELF_API NewsAgent : public IAgent
{
public:
	RTTI_DECL();

	NewsAgent() : m_NumberOfArticles( 10 )
	{}

	//! ISerializable interface
	void Serialize(Json::Value & json);
	void Deserialize(const Json::Value & json);

	//! IAgent interface
	virtual bool OnStart();
	virtual bool OnStop();

private:
	//! Data
	NewsIntent::SP  m_spActive;				// TODO: This needs to be moved into a Request object
	int				m_NumberOfArticles;

	//! Event Handlers
	void            OnNewsIntent(const ThingEvent & a_ThingEvent);
	void            OnNewsData(const Json::Value & a_Callback);
};

#endif //SELF_NEWSAGENT_H
