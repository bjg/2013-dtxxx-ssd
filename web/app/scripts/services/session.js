'use strict';

angular.module('webApp')
  .factory('Session', function ($resource) {
    return $resource('/api/session/');
  });
