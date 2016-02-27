/*
 * sf-velocity-reader.h
 *
 *  Created on: Feb 26, 2016
 *      Author: rice
 */

#ifndef SRC_SF_VELOCITY_READER_H_
#define SRC_SF_VELOCITY_READER_H_

extern "C" {
#include <rsf.h>
}

class SfVelocityReader {
public:
  SfVelocityReader(sf_file &f);
  void readAndBcast(float *vv, size_t count, int rank);
  virtual ~SfVelocityReader();

private:
  sf_file &file;
};


#endif /* SRC_SF_VELOCITY_READER_H_ */
