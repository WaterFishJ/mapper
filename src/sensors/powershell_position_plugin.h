/*
 *    Copyright 2019 Kai Pastor
 *
 *    This file is part of OpenOrienteering.
 *
 *    OpenOrienteering is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    OpenOrienteering is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with OpenOrienteering.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef OPENORIENTEERING_POWERSHELL_POSITION_PLUGIN_H
#define OPENORIENTEERING_POWERSHELL_POSITION_PLUGIN_H

#include <QGeoPositionInfoSourceFactory>
#include <QObject>
#include <QString>

class QGeoAreaMonitorSource;
class QGeoPositionInfoSource;
class QGeoSatelliteInfoSource;

namespace OpenOrienteering
{

/**
 * A plugin for properly registering PowershellPositionSource.
 */
class PowershellPositionPlugin : public QObject, public QGeoPositionInfoSourceFactory 
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "org.qt-project.qt.position.sourcefactory/5.0"
	                  FILE "powershell_position_plugin.json")
	Q_INTERFACES(QGeoPositionInfoSourceFactory)
public:
	PowershellPositionPlugin(QObject* parent = nullptr);
	PowershellPositionPlugin(const PowershellPositionPlugin&) = delete;
	PowershellPositionPlugin(PowershellPositionPlugin&&) = delete;
	PowershellPositionPlugin& operator=(const PowershellPositionPlugin&) = delete;
	PowershellPositionPlugin&& operator=(PowershellPositionPlugin&&) = delete;
	~PowershellPositionPlugin() override;
	QGeoAreaMonitorSource* areaMonitor(QObject* parent) override;
	QGeoPositionInfoSource* positionInfoSource(QObject* parent) override;
	QGeoSatelliteInfoSource* satelliteInfoSource(QObject* parent) override;
};


}  // namespace OpenOrienteering

#endif  // OPENORIENTEERING_POWERSHELL_POSITION_PLUGIN_H
