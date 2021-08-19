#include "space_age.h"

namespace space_age {

constexpr double earth_year_in_seconds = 31557600;
constexpr double mercury_year_in_earth_seconds = earth_year_in_seconds * 0.24084670;
constexpr double venus_year_in_earth_seconds = earth_year_in_seconds * 0.61519726;
constexpr double mars_year_in_earth_seconds = earth_year_in_seconds * 1.88081580;
constexpr double jupiter_year_in_earth_seconds = earth_year_in_seconds * 11.86261500;
constexpr double saturn_year_in_earth_seconds = earth_year_in_seconds * 29.44749800;
constexpr double uranus_year_in_earth_seconds = earth_year_in_seconds * 84.01684600;
constexpr double neptune_year_in_earth_seconds = earth_year_in_seconds * 164.79132000;

space_age::space_age(double age_in_seconds) : age_in_seconds_(age_in_seconds) {}

inline double space_age::seconds() const {
  return age_in_seconds_;
}

double space_age::on_earth() const {
  return seconds() / earth_year_in_seconds;
}

double space_age::on_mercury() const {
  return seconds() / mercury_year_in_earth_seconds;
}
double space_age::on_venus() const {
  return seconds() / venus_year_in_earth_seconds;
}

double space_age::on_mars() const {
  return seconds() / mars_year_in_earth_seconds;
}

double space_age::on_jupiter() const {
  return seconds() / jupiter_year_in_earth_seconds;
}

double space_age::on_saturn() const {
  return seconds() / saturn_year_in_earth_seconds;
}

double space_age::on_uranus() const {
  return seconds() / uranus_year_in_earth_seconds;
}

double space_age::on_neptune() const {
  return seconds() / neptune_year_in_earth_seconds;
}

}  // namespace space_age
