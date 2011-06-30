/*
* Copyright (C) 2007-2011 German Aerospace Center (DLR/SC)
*
* Created: 2010-08-13 Markus Litz <Markus.Litz@dlr.de>
* Changed: $Id: CommandLineParameters.h 4591 2011-04-15 15:28:24Z litz_ma $
*
* Version: $Revision: 4591 $
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* � � http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
#ifndef COMMANDLINEPARAMETERS_H
#define COMMANDLINEPARAMETERS_H

#include <QString>

struct CommandLineParameters {
    QString initialFilename;
    QString windowTitle;
    QString modelUID;
    QString controlFile;
};

extern struct CommandLineParameters PARAMS;

#endif /* COMMANDLINEPARAMETERS_H */